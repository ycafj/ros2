#include <polygon_base/regular_polygon.hpp>
#include <cmath>

namespace polygon_plugins
{
  class Length : public polygon_base::RegularPolygon
  {
    public:
      void initialize(double X1, double Y1, double X2, double Y2) override
      {
        X1_ = X1;
        Y1_ = Y1;
        X2_ = X2;
        Y2_ = Y2;
      }

      double length() override
      {
        return sqrt(pow(X2_-X1_,2)+pow(Y2_-Y1_,2));
      }

    protected:
      double X1_;
      double Y1_;
      double X2_;
      double Y2_;
  };

  
}

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(polygon_plugins::Length, polygon_base::RegularPolygon)
