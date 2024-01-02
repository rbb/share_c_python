#include <stdio.h>

// Based on "Heterogeneous Types Example" from:
// https://scipy-cookbook.readthedocs.io/items/Ctypes.html

extern "C" {
  typedef struct diff_rec_t {
    int week;
    int time;
    int sv;
    float el;
    float az;
    float diff;
  } diff_rec;


  void print_diff_rec(diff_rec* r, int Nelems)
  {
    int i;
    int Nrec = Nelems / 9; // TODO: have the compiler calculate 9 from the struct
    printf("Nelems: %d\n", Nelems);
    printf("Nrec: %d\n", Nelems/9);
    printf("Week\tTime\tSV\tEl\tAz\tdiff\n");
    for (i=0;i<Nelems;++i) {
      printf("%d\t%d\t%d\t%f\t%f\t%f\n",
          r[i].week,
          r[i].time,
          r[i].sv,
          r[i].el,
          r[i].az,
          r[i].diff);
    }
  }

  int simulate_diff(diff_rec* r, int* Nelems) {
    diff_rec myrec[] = {
      //Week   Time    SV  El      Az       diff
      {2289, 245101000, 3, 42.000, 199.750, 0.1,},
      {2289, 245101000, 4, 42.000, 199.750, 0.2,},
      {2289, 245101000, 5, 42.000, 199.750, 0.5,}
    };
    r = myrec;
    int new_Nelems = sizeof(myrec)/sizeof(myrec[0]);
    *Nelems = new_Nelems;
    return new_Nelems;
  }
}
