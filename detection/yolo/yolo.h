#ifndef YOLO_H
#define YOLO_H
#include <stdio.h>  // for snprintf
#include <string>
#include <vector>
#include <math.h>
#include <fstream>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "boost/algorithm/string.hpp"
//#include "google/protobuf/text_format.h"
#include <QDateTime>

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/net.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/util/io.hpp"

#define max_s(a, b) (((a)>(b)) ? (a) :(b))
#define min_s(a, b) (((a)<(b)) ? (a) :(b))

using caffe::Blob;
using caffe::Layer;
using caffe::Caffe;
using caffe::Net;
using std::string;
using boost::shared_ptr;
using std::ifstream;
using std::vector;

class Yolo
{
public:
    Yolo();
    void YoloDetection(const string& im_name);
    void nms(double overlap);

    shared_ptr<Net<float> > net_yolo;
    vector<vector<float> >  pre_all;
};

#endif // YOLO_H
