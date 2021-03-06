
# ofxEquidistantProjection
[![Build Status](https://travis-ci.org/hiroMTB/ofxEquidistantProjection.svg?branch=master)](https://travis-ci.org/hiroMTB/ofxEquidistantProjection)
[![Build status](https://ci.appveyor.com/api/projects/status/fh9f01w6yjqsyty7?svg=true)](https://ci.appveyor.com/project/hiroMTB/ofxequidistantprojection)

3D view
![screenshot2](screenshot1.png)

Rendered texture (domemaster format)
![screenshot2](screenshot2.png)

openFrameworks addon for equidistant projection (hemisphere mapping, domemaster for planetarium material)

Based on this paper (Japanese)

+ https://www.jstage.jst.go.jp/article/iteac/2008/0/2008__17-6-1_/_article/-char/ja/
+ https://www.jstage.jst.go.jp/article/iteac/2009/0/2009__13-2-1_/_article/-char/ja/

## TODO
+ check on Windows platform
+ reconsider about naming, maybe ofxEquidistantCam? or ofxEisheyeCam?
+ consider about pull request against ofxDomemaster (https://github.com/charlesveasey/ofxDomemaster)
+ add Inv-equidistant projection shader which convert 2D texture data to 3D point data.

## DONE
+ add GL2 shader
+ add GL3 shader
+ add geometry shader for polygon/line interporation

## Cubemap VS ofxEquidistantProjection
Cubemap, rendered with another addon
![cubemap](cubemap_00250.png)

ofxEquidistantProjection, rendered with this addon
![ofxEquidistantProjection](ofxEquidistantProjection_00250.png)
