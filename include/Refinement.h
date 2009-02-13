#ifndef _Refinement_H_
#define _Refinement_H_

#include <basics.h>
#include <gridProcessing.h>

BEGIN_CRUSTA

class LodEvaluator;
class VisibilityEvaluator;

/**
    Base class for refinement algorithms on base patches.

    \todo maintains scope hierarchy
    \todo exports changes to active scopes
    \todo queryable active scopes
    \todo queryable scope neighborhood
*/
class Refinement
{
public:
    virtual ~Refinement() {}

    virtual void addDataSlots(uint numSlots=1) = 0;

    /** generate the ideal multi-scale tiling given the LOD criterion */
    virtual void refine(VisibilityEvaluator& visibility, LodEvaluator& lod) = 0;
    /** traverse leaf nodes of the refinement and apply given scope callbacks */
    virtual void traverseLeaves(gridProcessing::ScopeCallbacks& callbacks) = 0;
};

END_CRUSTA

#endif //_Refinement_H_
