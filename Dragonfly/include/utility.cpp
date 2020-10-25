#include "utility.h"
#include "Object.h"
#include "WorldManager.h"
#include "Box.h"



bool df::positionsIntersect(Vector p1, Vector p2)
{
    if (abs(p1.getX() - p2.getX()) <= 1 && abs(p1.getY() - p2.getY()) <= 1)
    {
        return true;
    }
    return false;
}

bool df::boxIntersectsBox(Box box1, Box box2)
{

    /*    
      ax1,ay1   ----------------
                |              |
                |     A        |
                |              |
                ________________   ax2,ay2
    


                            bx1,by1 ----------------
                                    |              |
                                    |      B       |
                                    |              |
                                    ________________   bx2,by2

          
    */


    //horizontal test
    bool x_overlapAinB = box2.getCorner().getX() <= box1.getCorner().getX()                             //bx1<=ax2 ?
                      && box1.getCorner().getX() <= (box2.getCorner().getX() + box2.getHorizontal());   //ax1<=bx2 ?

    bool x_overlapBinA = box1.getCorner().getX() <= box2.getCorner().getX()                             //ax1<=bx1 ?
                      && box2.getCorner().getX() <= (box1.getCorner().getX() + box1.getHorizontal());   //bx1<=ax2 ?


    //vertical test
    bool y_overlapAinB = box2.getCorner().getY() <= box1.getCorner().getY()                             //by1<=ay1 ?
                      && box1.getCorner().getY() <= (box2.getCorner().getY() + box2.getVertical());     //ay1<=by2 ?

    bool y_overlapBinA = box1.getCorner().getY() <= box2.getCorner().getY()                             //ay1<=by1 ?
                      && box1.getCorner().getY() <= (box2.getCorner().getY() + box2.getVertical());     //by1<=ay2 ?

    if ((x_overlapAinB || x_overlapBinA) && (y_overlapAinB || y_overlapBinA))
    {
        return true;
    }

    return false;
}

df::Box df::getWorldBox(const Object* p_o)
{    
    return getWorldBox(p_o , p_o->getPosition());
}

df::Box df::getWorldBox(const Object* p_o, Vector where)
{
    if (p_o)
    {
        Box temp_box = p_o->getBox();
        Vector cornor = temp_box.getCorner();

        cornor.setX(cornor.getX() + where.getX());
        cornor.setY(cornor.getY() + where.getY());
        temp_box.setCorner(cornor);

        return temp_box;
    }
    return Box();
}

df::Vector df::worldToView(Vector world_pos)
{
    Vector view_origin = WM.getView().getCorner();

    int view_x = view_origin.getX();
    int view_y = view_origin.getY();

    Vector view_pos(world_pos.getX() - view_x, world_pos.getY() - view_y);

    return view_pos;
}

//Vector df::viewToWorld(Vector view_pos)
//{
//    return Vector();
//}
