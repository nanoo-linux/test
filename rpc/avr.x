const MAXAVGSIZE  = 200;

struct input_data {
  double input_data<200>;
};

typedef struct input_data input_data;

program AVERAGEPROG {
    version AVERAGEVERS {
        double average(input_data) = 1;
    } = 1;
} = 22855;
