#ifndef _Shape_H_
#define _Shape_H_

#include <iostream>
#include <list>

#include <crusta/glbasics.h>
#include <crusta/CrustaComponent.h>
#include <crusta/IdGenerator.h>


namespace crusta {


class NodeData;

/**\todo should shape really be a crusta component and interact with the map
manager directly? Vis2010 */
///\todo comment on this more once the interface is stable
/**
    Abstract interface to shapes used for mapping.
*/
class Shape : public CrustaComponent
{
public:
///\todo fix the abstraction of the data Vis2010
    struct ControlPoint
    {
        ControlPoint();
        ControlPoint(const ControlPoint& other);
        ControlPoint(const Geometry::Point<double,3>& position);
        ControlPoint(const FrameStamp& attributeStamp, const Geometry::Point<double,3>& iPos);

        /** stamp used to age parts of the line segment. In particular, the line
            data needs to be regenerated if its stamp is older than this stamp.
            Such cases occur after moving a control point where all subsequent
            points need to have their coordinate updated. Changing the symbol
            of a shape is a case where all the overlaped node's line data must
            be updated. */
        FrameStamp stamp;
        Geometry::Point<double,3>     pos;
        Scalar     coord;
    };
    typedef std::list<ControlPoint>          ControlPointList;
///\todo this should actually be a const_iterator
    typedef ControlPointList::iterator       ControlPointHandle;
    typedef ControlPointList::const_iterator ControlPointConstHandle;
    typedef std::list<ControlPointHandle>    ControlPointHandleList;

    enum ControlType
    {
        CONTROL_POINT,
        CONTROL_SEGMENT,
        CONTROL_INVALID
    };
    enum End
    {
        END_FRONT,
        END_BACK,
        END_INVALID
    };

    struct Symbol
    {
        int   id;
        Color color;
        Color originSize;

        Symbol();
        Symbol(int iId, const Color& iColor);
        Symbol(int iId, float iRed, float iGreen, float iBlue);
    };

    struct ControlId
    {
        ControlId();
        ControlId(const ControlId& other);
        ControlId(int type, const ControlPointHandle& handle);

        bool isValid()   const;
        bool isPoint()   const;
        bool isSegment() const;

        ControlId& operator=(const ControlId& other);
        bool       operator ==(const ControlId& other) const;
        bool       operator !=(const ControlId& other) const;

        int                type;
        ControlPointHandle handle;

///\todo debug, remove
friend std::ostream& operator<<(std::ostream& os, const ControlId& cid);
    };

    class IntersectionFunctor
    {
    public:
        virtual ~IntersectionFunctor() {}
        virtual void operator()(NodeData& node, bool isLeaf) = 0;
    };

    Shape(Crusta* iCrusta);
    virtual ~Shape();

    ControlId select(const Geometry::Point<double,3>& pos, double& dist, double pointBias=1.0);
    ControlId selectPoint(const Geometry::Point<double,3>& pos, double& dist);
    ControlId selectSegment(const Geometry::Point<double,3>& pos, double& dist);
    ControlId selectExtremity(const Geometry::Point<double,3>& pos, double& dist, End& end);

    virtual void setControlPoints(const std::vector<Geometry::Point<double,3> >& newControlPoints);

    virtual ControlId addControlPoint(const Geometry::Point<double,3>& pos, End end=END_BACK);
    virtual void moveControlPoint(const ControlId& id, const Geometry::Point<double,3>& pos);
    virtual void removeControlPoint(const ControlId& id);
    virtual ControlId refine(const ControlId& id, const Geometry::Point<double,3>& pos);

    ControlId previousControl(const ControlId& id) const;
    ControlId nextControl(const ControlId& id) const;

    void                     setId(const IdGenerator32::Id& nId);
    const IdGenerator32::Id& getId() const;
    void                     setSymbol(const Symbol& nSymbol);
    const Symbol&            getSymbol() const;
    ControlPointList&        getControlPoints();
    const ControlPointList&  getControlPoints() const;

    /** for debugging purposes. Check the validity of the control. Expected to
        perform very poorly */
    bool isValid(const ControlId& control) const;

    static       Symbol    DEFAULT_SYMBOL;
    static const ControlId BAD_ID;

protected:
    IdGenerator32::Id id;
    Symbol            symbol;
    ControlPointList  controlPoints;
};


///\todo debug, remove
std::ostream& operator<<(std::ostream& os,
                         const Shape::ControlPointHandle& cid);


} //namespace crusta


#endif //_Shape_H_
