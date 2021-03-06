// GNUPlot1.cpp : Defines the entry point for the console application.
//

#include <windows.h>
#include <CONIO.H>
//#include <unistd.h>
#include "gnuplot_i.hpp"

#define SLEEP_LGTH 1
#define NPOINTS    50

int main(int argc, char* argv[]){
  vector<double> x;
  vector<double> y;
  int i;


  cout << "*** example of gnuplot control through C++ ***" << endl;

  //
  // Using the GnuplotException class
  //
  try{
    Gnuplot g1 = Gnuplot("lines");

    //
    // Slopes
    // 
    cout << "*** plotting slopes" << endl;
    cout << "y = x" << endl;
    g1.plot_slope(1.0, 0.0, "unity slope");
    Sleep(SLEEP_LGTH);

    cout << "y = 2*x" << endl;
    g1.plot_slope(2.0, 0.0, "y=2x");
    Sleep(SLEEP_LGTH);

    cout << "y = -x" << endl;
    g1.plot_slope(-1.0, 0.0, "y=-x");
    Sleep(SLEEP_LGTH);

    //
    // Equations
    //
    g1.reset_plot();
    cout << endl << endl << "*** various equations" << endl;
    cout << "y = sin(x)" << endl;
    g1.plot_equation("sin(x)", "sine");
    Sleep(SLEEP_LGTH);

    cout << "y = log(x)" << endl;
    g1.plot_equation("log(x)", "logarithm");
    Sleep(SLEEP_LGTH);

    cout << "y = sin(x) * cos(2*x)" << endl;
    g1.plot_equation("sin(x)*cos(2*x)", "sine product");
    Sleep(SLEEP_LGTH);

    //
    // Styles
    //
    g1.reset_plot();
    cout << endl << endl << "*** showing styles" << endl;
    cout << "sine in points" << endl;
    g1.set_style("points");
    g1.plot_equation("sin(x)", "sine");
    Sleep(SLEEP_LGTH);

    cout << "sine in impulses" << endl;
    g1.set_style("impulses");
    g1.plot_equation("sin(x)", "sine");
    Sleep(SLEEP_LGTH);

    cout << "sine in steps" << endl;
    g1.set_style("steps");
    g1.plot_equation("sin(x)", "sine");
    Sleep(SLEEP_LGTH);

    //
    // User defined 1d and 2d point sets
    //
    cout << endl << endl << "*** user-defined lists of doubles" << endl;
    for (i = 0; i < NPOINTS; i++)
      x.push_back((double)i * (double)i);
    g1.reset_plot();
    g1.set_style("impulses");
    g1.plot_x(x, "user-defined doubles");
    Sleep(SLEEP_LGTH);


    cout << endl << endl << "*** user-defined lists of points" << endl;
    x.clear();
    for (i = 0; i < NPOINTS; i++)
    {
      x.push_back((double)i);
      y.push_back((double)i * (double)i);
    }
    g1.reset_plot();
    g1.set_style("lines");
    g1.plot_xy(x, y, "user-defined points");
    Sleep(SLEEP_LGTH);

    //
    // Multiple output screens
    //
    cout << endl << endl;
    cout << "*** multiple output windows" << endl;
    g1.reset_plot();
    g1.set_style("lines");

    Gnuplot g2 = Gnuplot("lines");
    Gnuplot g3 = Gnuplot("lines");

    cout << "window 1: sin(x)" << endl;
    g1.plot_equation("sin(x)", "sin(x)");
    Sleep(SLEEP_LGTH);

    cout << "window 2: x*sin(x)" << endl;
    g2.plot_equation("x*sin(x)", "x*sin(x)");
    Sleep(SLEEP_LGTH);

    cout << "window 3: log(x)/x" << endl;
    g3.plot_equation("log(x)/x", "log(x)/x");
    Sleep(SLEEP_LGTH);

    Gnuplot g4 = Gnuplot("lines");
    cout << "window 4: sin(x)/x" << endl;
    g4.plot_equation("sin(x)/x", "sin(x)/x");
    Sleep(SLEEP_LGTH);

    getchar();
  }
  catch (GnuplotException ge)
  {
    cout << ge.what() << endl;
  }

  cout << endl << "*** end of gnuplot example" << endl;

  return 0;
}
