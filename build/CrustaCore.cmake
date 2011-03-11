add_library(CrustaCore SHARED
    ../include/GL/glew.h
    ../include/GL/GlProgram.h
    ../include/GL/glxew.h
    ../include/GL/VruiGlew.h
    ../include/GLMotif/ColorHexagon.h
    ../include/GLMotif/ColorMapEditor.h
    ../include/GLMotif/ColorMapInOut.h
    ../include/GLMotif/ColorPicker.h
    ../include/GLMotif/ColorPickerWindow.h
    ../include/GLMotif/FileAndFolderSelectionDialog.h
    ../include/GLMotif/PaletteEditor.h
    ../include/GLMotif/RangeEditor.h
    ../include/GLMotif/RelativeSlider.h
    ../include/Misc/ColorMap.h

    ../include/crusta/basics.h
    ../include/crusta/Cache.h
    ../include/crusta/Cache.hpp
    ../include/crusta/checkGl.h
    ../include/crusta/ColorMapper.h
    ../include/crusta/Crusta.h
    ../include/crusta/CrustaComponent.h
    ../include/crusta/CrustaSettings.h
    ../include/crusta/CrustaVisualizer.h
    ../include/crusta/DataIndex.h
    ../include/crusta/DataManager.h
    ../include/crusta/DemHeight.h
    ../include/crusta/DemHeightGlobeData.h
    ../include/crusta/DebugTool.h
    ../include/crusta/FocusViewEvaluator.h
    ../include/crusta/FrustumVisibility.h
    ../include/crusta/GlobeData.h
    ../include/crusta/GlobeFile.h
    ../include/crusta/GlobeFile.hpp
    ../include/crusta/Homography.h
    ../include/crusta/IdGenerator.h
    ../include/crusta/LayerData.h
    ../include/crusta/LayerDataGlobeData.h
    ../include/crusta/LightingShader.h
    ../include/crusta/LodEvaluator.h
    ../include/crusta/map/MapManager.h
    ../include/crusta/map/MapTool.h
    ../include/crusta/map/Polyline.h
    ../include/crusta/map/PolylineRenderer.h
    ../include/crusta/map/PolylineTool.h
    ../include/crusta/map/Shape.h
    ../include/crusta/PixelOps.h
    ../include/crusta/PixelOps.hpp
    ../include/crusta/Polyhedron.h
    ../include/crusta/PolyhedronLoader.h
    ../include/crusta/QuadCache.h
    ../include/crusta/QuadCache.hpp
    ../include/crusta/QuadNodeData.h
    ../include/crusta/QuadNodeDataBundles.h
    ../include/crusta/QuadTerrain.h
    ../include/crusta/QuadtreeFile.h
    ../include/crusta/QuadtreeFile.hpp
    ../include/crusta/Refinement.h
    ../include/crusta/Refinement.hpp
    ../include/crusta/Scope.h
    ../include/crusta/Scope.hpp
    ../include/crusta/Section.h
    ../include/crusta/shader/ShaderAtlasDataSource.h
    ../include/crusta/shader/ShaderColorMapper.h
    ../include/crusta/shader/ShaderColorMixer.h
    ../include/crusta/shader/ShaderColorMultiplier.h
    ../include/crusta/shader/ShaderColorReader.h
    ../include/crusta/shader/ShaderDataSource.h
    ../include/crusta/shader/ShaderDecoratedLineRenderer.h
    ../include/crusta/shader/ShaderFileFragment.h
    ../include/crusta/shader/ShaderFragment.h
    ../include/crusta/shader/ShaderMultiDataSource.h
    ../include/crusta/shader/ShaderTopographySource.h
    ../include/crusta/SliceTool.h
    ../include/crusta/Sphere.h
    ../include/crusta/StatsManager.h
    ../include/crusta/SurfaceApproximation.h
    ../include/crusta/SurfacePoint.h
    ../include/crusta/SurfaceProbeTool.h
    ../include/crusta/SurfaceProjector.h
    ../include/crusta/SurfaceTool.h
    ../include/crusta/TextureColor.h
    ../include/crusta/TextureColorGlobeData.h
    ../include/crusta/TileIndex.h
    ../include/crusta/Timer.h
    ../include/crusta/Tool.h
    ../include/crusta/TreeIndex.h
    ../include/crusta/Triacontahedron.h
    ../include/crusta/Triangle.h
    ../include/crusta/Vector3ui8.h
    ../include/crusta/ViewLod.h
    ../include/crusta/VisibilityEvaluator.h
    ../include/crusta/Visualizer.h

    ../source/GL/glew.c
    ../source/GL/GlProgram.cpp
    ../source/GL/VruiGlew.cpp
    ../source/GLMotif/ColorHexagon.cpp
    ../source/GLMotif/ColorMapEditor.cpp
    ../source/GLMotif/ColorMapInOut.cpp
    ../source/GLMotif/ColorPicker.cpp
    ../source/GLMotif/ColorPickerWindow.cpp
    ../source/GLMotif/FileAndFolderSelectionDialog.cpp
    ../source/GLMotif/PaletteEditor.cpp
    ../source/GLMotif/RangeEditor.cpp
    ../source/GLMotif/RelativeSlider.cpp
    ../source/Misc/ColorMap.cpp

    ../source/crusta/ColorMapper.cpp
    ../source/crusta/Crusta.cpp
    ../source/crusta/CrustaSettings.cpp
    ../source/crusta/CrustaVisualizer.cpp
    ../source/crusta/DataIndex.cpp
    ../source/crusta/DataManager.cpp
    ../source/crusta/DebugTool.cpp
    ../source/crusta/FocusViewEvaluator.cpp
    ../source/crusta/FrustumVisibility.cpp
    ../source/crusta/Homography.cpp
    ../source/crusta/LightingShader.cpp
    ../source/crusta/LodEvaluator.cpp
    ../source/crusta/map/MapManager.cpp
    ../source/crusta/map/MapTool.cpp
    ../source/crusta/map/Polyline.cpp
    ../source/crusta/map/PolylineRenderer.cpp
    ../source/crusta/map/PolylineTool.cpp
    ../source/crusta/map/Shape.cpp
    ../source/crusta/PolyhedronLoader.cpp
    ../source/crusta/QuadCache.cpp
    ../source/crusta/QuadNodeData.cpp
    ../source/crusta/QuadNodeDataBundles.cpp
    ../source/crusta/QuadTerrain.cpp
    ../source/crusta/Scope.cpp
    ../source/crusta/Section.cpp
    ../source/crusta/shader/ShaderAtlasDataSource.cpp
    ../source/crusta/shader/ShaderColorMapper.cpp
    ../source/crusta/shader/ShaderColorMixer.cpp
    ../source/crusta/shader/ShaderColorMultiplier.cpp
    ../source/crusta/shader/ShaderColorReader.cpp
    ../source/crusta/shader/ShaderDataSource.cpp
    ../source/crusta/shader/ShaderDecoratedLineRenderer.cpp
    ../source/crusta/shader/ShaderFileFragment.cpp
    ../source/crusta/shader/ShaderFragment.cpp
    ../source/crusta/shader/ShaderMultiDataSource.cpp
    ../source/crusta/shader/ShaderTopographySource.cpp
    ../source/crusta/SliceTool.cpp
    ../source/crusta/Sphere.cpp
    ../source/crusta/StatsManager.cpp
    ../source/crusta/SurfaceApproximation.cpp
    ../source/crusta/SurfacePoint.cpp
    ../source/crusta/SurfaceProbeTool.cpp
    ../source/crusta/SurfaceProjector.cpp
    ../source/crusta/SurfaceTool.cpp
    ../source/crusta/Tool.cpp
    ../source/crusta/TreeIndex.cpp
    ../source/crusta/Triacontahedron.cpp
    ../source/crusta/ViewLod.cpp
    ../source/crusta/Visualizer.cpp
)

# Pass Vrui flags and the share path to the sources for compilation
set_target_properties(CrustaCore PROPERTIES
    COMPILE_FLAGS "${VRUI_CFLAGS}")

target_link_libraries(CrustaCore ${VRUI_LINKFLAGS} ${GDAL_LIBRARY}
    ${X11_OPENGL_GLU_LIBRARIES})
