[![Build Status](https://travis-ci.org/hiroMTB/ofxEquidistantProjection.svg?branch=master)](https://travis-ci.org/hiroMTB/ofxEquidistantProjection)
[![Build status](https://ci.appveyor.com/api/projects/status/fh9f01w6yjqsyty7?svg=true)](https://ci.appveyor.com/project/hiroMTB/ofxequidistantprojection)

# ofxEquidistantProjection (work in progress)
openFrameworks addon for equidistant projection (hemisphere mapping, domemaster for planetarium material)
based on this paper (Japanese)
https://www.jstage.jst.go.jp/article/iteac/2008/0/2008__17-6-1_/_article/-char/ja/

## TODO
+ add GLSL3 shader
+ check on Windows platform
+ add geometry shader for polygon/line interporation
+ reconsider about naming, maybe ofxEquidistantCam? or ofxEisheyeCam?
+ consider about pull request against ofxDomemaster (https://github.com/charlesveasey/ofxDomemaster)
+ add Inv-equidistant projection shader which convert 2D texture data to 3D point data.

## DONE
+ GLSL2 shader works ok
