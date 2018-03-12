/****************************************************************************
**
** Copyright (C) 2014-2017 Dinu SV.
** (contact: mail@dinusv.com)
** This file is part of Live CV Application.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
****************************************************************************/

#include "starfeaturedetector.h"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

namespace lv{

StarFeatureDetector::StarFeatureDetector(QQuickItem *parent)
    : QFeatureDetector(cv::xfeatures2d::StarDetector::create(), parent)
{
}

StarFeatureDetector::~StarFeatureDetector(){
}

void StarFeatureDetector::initialize(const QVariantMap &settings){
    int maxSize                = 16;
    int responseThreshold      = 30;
    int lineThresholdProjected = 10;
    int lineThresholdBinarized = 8;
    int suppressNonmaxSize     = 5;

    if ( settings.contains("maxSize") )
         maxSize = settings["maxSize"].toInt();
    if ( settings.contains("responseThreshold") )
        responseThreshold = settings["responseThreshold"].toInt();
    if ( settings.contains("lineThresholdProjected") )
        lineThresholdProjected = settings["lineThresholdProjected"].toInt();
    if ( settings.contains("lineThresholdBinarized") )
        lineThresholdBinarized = settings["lineThresholdBinarized"].toInt();
    if ( settings.contains("suppressNonmaxSize") )
        suppressNonmaxSize = settings["suppressNonmaxSize"].toInt();

    initializeDetector(cv::xfeatures2d::StarDetector::create(
        maxSize, responseThreshold, lineThresholdProjected, lineThresholdBinarized, suppressNonmaxSize
    ));
}

}// namespace
