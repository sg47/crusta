#ifndef _CrustaSettings_H_
#define _CrustaSettings_H_


#include <string>
#include <vector>

#include <crustacore/basics.h>
#include <crusta/glbasics.h>


namespace crusta {


class CrustaSettings
{
public:
    typedef std::vector<std::string> Strings;

    CrustaSettings();

    void mergeFromCfgFile(const std::string& path);
    void setFromCfg();

    /** name of the sphere onto which data is mapped */
    std::string globeName;
    /** radius of the sphere onto which data is mapped */
    double globeRadius;

    ///\{ material properties of the terrain surface
    float terrainDefaultHeight;
    Color terrainDefaultColor;
    float terrainDefaultLayerfData;

    Color terrainAmbientColor;
    Color terrainDiffuseColor;
    Color terrainEmissiveColor;
    Color terrainSpecularColor;
    float terrainShininess;
    ///\}

    ///\{ cache settings
    int cacheMainNodeSize;
    int cacheMainGeometrySize;
    int cacheMainColorSize;
    int cacheMainLayerfSize;
    int cacheGpuGeometrySize;
    int cacheGpuColorSize;
    int cacheGpuLayerfSize;
    int cacheGpuCoverageSize;
    int cacheGpuLineDataSize;
    ///\}

    ///\{ data manager settings
    /** maximum number of data layers (depends on the number of dataId bits
        of DataIndex. Thus, the option is kept internal) */
    int dataManMaxDataLayers;
    /** impose a limit on the number of outstanding fetch requests. This
        minimizes processing outdated requests */
    int dataManMaxFetchRequests;
    ///\}

    ///\{ color mapper settings
    /** size of the color map */
    int colorMapTexSize;
    ///\}

    ///\{ decorated line settings
    /** flags if line mapping should be rendered decorated or not */
    bool  lineDecorated;
    float lineSymbolWidth;
    float lineSymbolLength;
///\todo these depend on GL capabilities and should be wrapped in GLObjects
    int   lineDataTexSize;
    float lineDataCoordStep;
    float lineDataStartCoord;
    int   lineCoverageTexSize;
    ///\}

    ///\{ surface projector settings
    bool surfaceProjectorRayIntersect;
    ///\}

    ///\{ Slice tool settings
    bool sliceToolEnable;
    ///\}

    // Level of detail
    float lodBias;
    float lodScale;

    bool sceneGraphViewerEnabled;
    Misc::ConfigurationFile cfgFile;
};


extern CrustaSettings* SETTINGS;


} //namespace crusta


#endif //_CrustaSettings_H_
