#ifndef _Crusta_H_
#define _Crusta_H_

#include <string>
#include <vector>

#include <GL/gl.h>
#include <GL/GLObject.h>
#include <Threads/Mutex.h>

#include <crusta/basics.h>
#include <crusta/CompositeShader.h>

class GLContextData;

BEGIN_CRUSTA

template <typename NodeDataType>
class CacheBuffer;

class Cache;
class DataManager;
class MapManager;
class QuadNodeMainData;
class QuadTerrain;

/** Main crusta class */
class Crusta : public GLObject
{
public:
    typedef std::vector<CacheBuffer<QuadNodeMainData>*> Actives;

    void init(const std::string& demFileBase, const std::string& colorFileBase);
    void shutdown();

///\todo fix this API. potentially deprecate
    /** query the height of the surface closest to the query point */
    double getHeight(double x, double y, double z);
    /** snap the given cartesian point to the surface of the terrain (at an
        optional offset) */
    Point3 snapToSurface(const Point3& pos, Scalar offset=Scalar(0));

    const FrameNumber& getCurrentFrame()   const;
    const FrameNumber& getLastScaleFrame() const;

    /** set the vertical exaggeration. Make sure to set this value within a
        frame callback so that it doesn't change during a rendering phase */
    void setVerticalScale(double newVerticalScale);
    /** retrieve the vertical exaggeration factor */
    double getVerticalScale() const;

    Cache*       getCache()       const;
    DataManager* getDataManager() const;
    MapManager*  getMapManager()  const;

    /** inform crusta of nodes that must be kept current */
    void submitActives(const Actives& touched);

    void frame();
    void display(GLContextData& contextData);

protected:
    typedef std::vector<QuadTerrain*> RenderPatches;

    struct GlData : public GLObject::DataItem
    {
        GlData();
        ~GlData();
        
        GLuint colorBuf;
        GLuint depthBuf;
        GLuint frameBuf;
        
        CompositeShader compositeShader;
    };

    /** make sure the bounding objects used for visibility and LOD checks are
        up-to-date wrt to the vertical scale */
    void confirmActives();

    /** prepares the rendering buffers for a new frame */
    void prepareBuffers(GlData* glData);

    /** keep track of the number of frames processed. Used, for example, by the
        cache to perform LRU that is aware of currently active nodes (the ones
        from the previous frame) */
    FrameNumber currentFrame;
    /** keep track of the last frame at which the vertical scale was modified.
        The vertical scale affects the bounding primitives for the nodes and
        these must be updated each time the scale changes. Validity of a node's
        semi-static data can be verified by comparison with this number */
    FrameNumber lastScaleFrame;

    /** the vertical scale to be applied to all surface elevations */
    double verticalScale;

    /** the cache management component */
    Cache* cache;
    /** the data management component */
    DataManager* dataMan;
    /** the mapping management component */
    MapManager* mapMan;

    /** the spheroid base patches used for rendering */
    RenderPatches renderPatches;

    /** the nodes that have been touch during the traversals of the previous
        frame */
    Actives actives;
    /** guarantee serial manipulation of the set of active nodes */
    Threads::Mutex activesMutex;

    /** the size of the current depth buffer */
    int bufSize[2];

//- inherited from GLObject
public:
   	virtual void initContext(GLContextData& contextData) const;
};

END_CRUSTA

#endif //_Crusta_H_
