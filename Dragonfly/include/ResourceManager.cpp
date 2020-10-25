#include <string>
#include <iostream>
#include <fstream>  


#include "LogManager.h"
#include "ResourceManager.h"



int df::ResourceManager::startUp()
{
    Manager::startUp();
    return 0;
}

void df::ResourceManager::shutDown()
{
    delete m_p_sprite[1];
    Manager::shutDown();

}

int df::ResourceManager::loadSprite(std::string filename, std::string label)
{
    std::ifstream rfile(filename);

    if (!rfile)
    {
        return -1;
    }

    Frame newFrame;

    std::vector<std::string> Header = readData(&rfile, HEADER_TOKEN);

    int frameCount = -1;
    int width = -1; 
    int height = -1; 
    int slowdown = -1;
    df::Color newColor;
    //parse for header
    for (auto i = Header.begin(); i != Header.end(); i++)
    {
        if (i->find("frames")!=std::string::npos)
        {
            i->erase(i->find("frames"), 6);
            frameCount = atoi(i->c_str());
        }
        else if (i->find("width") != std::string::npos)
        {
            i->erase(i->find("width"), 5);
            width = atoi(i->c_str());
        }
        else if (i->find("height") != std::string::npos)
        {
            i->erase(i->find("height"), 6);
            height = atoi(i->c_str());
        }
        else if (i->find("color") != std::string::npos)
        {
            i->erase(i->find("color"), 6);
            newColor = stringToColor(*i);
        }
        else if (i->find("slowdown") != std::string::npos)
        {
            i->erase(i->find("slowdown"), 8);
            slowdown = atoi(i->c_str());
        }
    }

    //check for validation
    if (frameCount < 0 || width < 0 || height < 0 || slowdown < 0)
    {
        return -1;
    }


    //parse for body
    std::vector<std::string> Body = readData(&rfile, BODY_TOKEN);
    std::string temp = "";

    df::Sprite* newSprite = new Sprite(frameCount);
    




    int heightIndex = 0;
    for (int i = 0; i < Body.size(); i++)
    {
        if (Body[i].compare("end") == 0)
        {
            if (heightIndex == height && !temp.empty())
            {
                //new frame forms
                Frame* newFrame = new Frame(width, height, temp);
                newSprite->addFrame(*newFrame);
                temp = "";
                heightIndex = 0;
                continue;
            }
            else
            {
                delete newSprite;
                return -1;  //height does not match
            }
        }

        temp += Body[i];
        heightIndex++;
    }
    newSprite->setLabel(label);
    newSprite->setHeight(height);
    newSprite->setWidth(width);
    newSprite->setSlowdown(slowdown);
    newSprite->setColor(newColor);
    m_p_sprite[m_sprite_count++] = newSprite;               //add sprite to sprite array


    //parse for footer
    std::vector<std::string> Footer = readData(&rfile, BODY_TOKEN);
    rfile.close();


    return 0;
}

int df::ResourceManager::unloadSprite(std::string label)
{

    for (int i = 0; i <= m_sprite_count - 1; i++)
    {
        if (label.compare(m_p_sprite[i]->getLabel()) == 0)
        {
            delete m_p_sprite[i];

            for (int j = i; j < m_sprite_count - 2; j++)
            {
                m_p_sprite[j] = m_p_sprite[j + 1];
            }
            m_sprite_count--;
            return 0;
        }
    }

    return -1;
}

df::ResourceManager::ResourceManager()
    : m_sprite_count(0)
    , m_sound_count(0)
    , m_music_count(0)
{
}

df::ResourceManager& df::ResourceManager::getInstance()
{
    static ResourceManager resourceManager;
    return resourceManager;
}

df::Sprite* df::ResourceManager::getSprite(std::string label) const
{
    for (int i = 0; i <= m_sprite_count - 1; i++)
    {
        if (label.compare(m_p_sprite[i]->getLabel())==0)
        {
            return m_p_sprite[i];
        }
    }
    return nullptr;
}

int df::ResourceManager::loadSound(std::string filename, std::string label)
{
    if (m_sound_count == MAX_SOUNDS)
    {
        LM.writeLog("Sound array full.");
        return -1;
    }

    if (m_sound[m_sound_count].loadSound(filename) == -1)
    {
        LM.writeLog("unable to load from file %s", filename.c_str());
        return -1;
    }

    m_sound[m_sound_count].setLabel(label);
    m_sound_count++;

    return 0;
}

int df::ResourceManager::unloadSound(std::string label)
{
    for (int i = 0; i < m_sound_count-1; i++)
    {
        if (label.compare(m_sound[i].getLabel()) == 0)
        {
            for (int j = i; j < m_sound_count - 2; j++)
            {
                m_sound[j] = m_sound[j + 1];
            }
            m_sound_count--;
            return 0;
        }
    }
    return -1;
}

df::Sound* df::ResourceManager::getSound(std::string label)
{
    for (auto& tmp : m_sound)
    {
        if (tmp.getLabel().compare(label) == 0)
        {
            return &tmp;
        }
    }
    return nullptr;
}

int df::ResourceManager::loadMusic(std::string filename, std::string label)
{
    if (m_music_count == MAX_MUSICS)
    {
        LM.writeLog("music array full.");
        return -1;
    }

    if (m_music[m_music_count].loadMusic(filename) == -1)
    {
        LM.writeLog("unable to load from file %s", filename.c_str());
        return -1;
    }

    m_music[m_music_count].setLabel(label);
    m_music_count++;

    return 0;
}

int df::ResourceManager::unloadMusic(std::string label)
{
    for (auto& tmp : m_music)
    {
        if (tmp.getLabel() == label)
        {
            tmp.setLabel("");
            m_music_count--;
            return 0;
        }
   }
    return -1;
}

df::Music* df::ResourceManager::getMusic(std::string label)
{
    for (auto& tmp : m_music)
    {
        if (tmp.getLabel().compare(label) == 0)
        {
            return &tmp;
        }
    }
    return nullptr;
}

//get next line from file, with error checking 
std::string getLine(std::ifstream* p_file)
{
    std::string line;
    getline(*p_file, line);
    if (!p_file)
    {
        return "";
    }
    return line;

}

//read in next section of data from file as vector of strings
//return vector(empty if error)
std::vector<std::string> readData(std::ifstream* p_file, std::string delimiter)
{
    std::string begin = "<" + delimiter + ">";
    std::string end = "</" + delimiter + ">";

    std::string s = getLine(p_file);

    std::vector<std::string> output = {};
    if (s.compare(begin))    //if not 0, they are different
    {
        return output;
    }



    s = getLine(p_file);
    while (s.compare(end) && !s.empty())
    {
        output.push_back(s);
        s = getLine(p_file);
    }

    if (s.empty())
    {
        return {};
    }

    return output;
}

//match token in vector of lines(e.g., "frames 5")
//return corresponding value (e.g., 5) (-1 if not found)
//remove any line that matches from vector
int matchLineInt(std::vector<std::string>* p_data, const char* token)
{
    auto i = p_data->begin();

    int number = -1;

    while (i != p_data->end())
    {
        if (i->compare(0, strlen(token), token) == 0)
        {
            number = atoi(i->substr(strlen(token) + 1).c_str());
            i = p_data->erase(i);
        }
        else
        {
            i++;
        }
    }

    return number;
}

//match token in vector of lines(e.g., "color green")
//return corresponding string (e.g., "green")("" if not found)
//remove any line that matches from vector.
std::string matchLineStr(std::vector<std::string>* p_data, const char* token)
{
    auto i = p_data->begin();

    std::string output = "";

    while (i != p_data->end())
    {
        if (i->compare(0, strlen(token), token) == 0)
        {
            output = i->substr(strlen(token) + 1);
            i = p_data->erase(i);
        }
        else
        {
            i++;
        }
    }

    return output;
}

//match frame lines until "end", clearing all from vector
//return frame
df::Frame matchFrame(std::vector<std::string>* p_data, int width, int height)
{
    std::string line, frame_str;

    for (int i = 1; i <= height; i++)
    {
        line = p_data->front();

        if (line.size() != width)
        {
            return df::Frame();   //error, return empty frame
        }

        p_data->erase(p_data->begin());

        frame_str += line;
    }
       
    line = p_data->front();
    if (line.compare(END_FRAME_TOKEN) == 0)
    {
        return df::Frame();  //error, return empty frame
    }

    p_data->erase(p_data->begin());

    return df::Frame(width, height, frame_str);

}

//remove '\r' from line (if there - typical of Windows
void discardCR(std::string& str)
{
    if (str.size() > 0 && str[str.size() - 1] == '\r')
    {
        str.erase(str.size() - 1);
    }
}

df::Color stringToColor(std::string& str)
{
    if (str.compare("black") == 0)
    {
        return df::Color::BLACK;
    }
    if (str.compare("red") == 0)
    {
        return df::Color::RED;
    }
    if (str.compare("green") == 0)
    {
        return df::Color::GREEN;
    }
    if (str.compare("yellow") == 0)
    {
        return df::Color::YELLOW;
    }
    if (str.compare("blue") == 0)
    {
        return df::Color::BLUE;
    }
    if (str.compare("magenta") == 0)
    {
        return df::Color::MAGENTA;
    }
    if (str.compare("cyan") == 0)
    {
        return df::Color::CYAN;
    }
    if (str.compare("white") == 0)
    {
        return df::Color::WHITE;
    }
    if (str.compare("custom") == 0)
    {
        return df::Color::CUSTOM;
    }

    return df::Color::UNDEFINED_COLOR;

}