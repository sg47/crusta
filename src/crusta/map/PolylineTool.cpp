#include <crusta/map/PolylineTool.h>

#include <cassert>

#include <crusta/Crusta.h>
#include <crusta/map/MapManager.h>
#include <crusta/map/Polyline.h>

#include <crusta/vrui.h>


namespace crusta {


PolylineTool::Factory* PolylineTool::factory = NULL;


PolylineTool::
PolylineTool(const Vrui::ToolFactory* iFactory,
             const Vrui::ToolInputAssignment& inputAssignment) :
    MapTool(iFactory, inputAssignment)
{
}
PolylineTool::
~PolylineTool()
{
}

Vrui::ToolFactory* PolylineTool::
init(Vrui::ToolFactory* parent)
{
    Factory* polylineFactory = new Factory("CrustaPolylineTool",
        "Polyline Drawing Tool", parent, *Vrui::getToolManager());

    //we want two buttons
    polylineFactory->setNumButtons(2);

    Vrui::getToolManager()->addClass(polylineFactory,
        Vrui::ToolManager::defaultToolFactoryDestructor);

    PolylineTool::factory = polylineFactory;

    return PolylineTool::factory;
}


void PolylineTool::
createShape(Shape*& shape, Shape::ControlId& control, const Geometry::Point<double,3>& pos)
{
    MapManager* mapMan   = crusta->getMapManager();
    Polyline*   newLine  = mapMan->createPolyline();
    newLine->setSymbol(mapMan->getActiveSymbol());

    shape   = newLine;
    control = shape->addControlPoint(pos);
}

void PolylineTool::
deleteShape(Shape*& shape, Shape::ControlId& control)
{
    Polyline* line = dynamic_cast<Polyline*>(shape);
    assert(line != NULL);
    crusta->getMapManager()->deletePolyline(line);

    shape   = NULL;
    control = Shape::BAD_ID;
}

void PolylineTool::
removeControl(Shape*& shape, Shape::ControlId& control)
{
    assert(shape!=NULL && control!=Shape::BAD_ID);

    switch (control.type)
    {
        case Shape::CONTROL_POINT:
        {
            shape->removeControlPoint(control);
            control = Shape::BAD_ID;
            break;
        }
        case Shape::CONTROL_SEGMENT:
        {
            /**NOTE: this relies on the implementation of removeControlPoint to
            keep Ids valid for existing controls before the deleted one! */
            shape->removeControlPoint(shape->nextControl(control));
            shape->removeControlPoint(shape->previousControl(control));
            control = Shape::BAD_ID;
            break;
        }
        default:
            break;
    }
}

void PolylineTool::
unselectShape(Shape*& shape, Shape::ControlId& control)
{
    assert(shape != NULL);
    //delete the polyline if there aren't at least two control points
    if (shape->getControlPoints().size() < 2)
        deleteShape(shape, control);

    shape   = NULL;
    control = Shape::BAD_ID;
}


PolylineTool::ShapePtrs PolylineTool::
getShapes()
{
    MapManager::PolylinePtrs& polylines =
        crusta->getMapManager()->getPolylines();

    int numPolylines = static_cast<int>(polylines.size());
    ShapePtrs shapes;
    shapes.resize(numPolylines);
    for (int i=0; i<numPolylines; ++i)
        shapes[i] = polylines[i];

    return shapes;
}


const Vrui::ToolFactory* PolylineTool::
getFactory() const
{
    return factory;
}


} //namespace crusta
