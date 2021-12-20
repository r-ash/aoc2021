#include <Rcpp.h>
#include <math.h>
#include "day_20.h"

int get_value(const std::vector<std::vector<int>> & pixels, int i, int j, int width, int height) {
  if (i < 0 || j < 0 || i > (width - 1) || j > (height - 1) ) {
    return 0;
  } else {
    return pixels[i][j];
  }
}

int bin_to_int(std::vector<int> bin) {
  int total = 0;
  int multiplier = 1;
  reverse(bin.begin(), bin.end());
  for (auto& it: bin) {
    total += it * multiplier;
    multiplier *= 2;
  }
  return total;
}

int get_number(const std::vector<std::vector<int>> & pixels, int i, int j) {
  int height = pixels.size();
  int width = pixels[0].size();
  std::vector<int> number;
  number.push_back(get_value(pixels, i - 1, j - 1, width, height));
  number.push_back(get_value(pixels, i - 1, j, width, height));
  number.push_back(get_value(pixels, i - 1, j + 1, width, height));
  number.push_back(get_value(pixels, i, j - 1, width, height));
  number.push_back(get_value(pixels, i, j, width, height));
  number.push_back(get_value(pixels, i, j + 1, width, height));
  number.push_back(get_value(pixels, i + 1, j - 1, width, height));
  number.push_back(get_value(pixels, i + 1, j, width, height));
  number.push_back(get_value(pixels, i + 1, j + 1, width, height));
  return bin_to_int(number);
}

std::vector<std::vector<int>> enhance_pixles(const std::vector<std::vector<int>> & pixels, const std::string & algorithm) {
  std::vector<std::vector<int>> enhanced;
  for (int i = 0; i < pixels[0].size(); i++) {
    std::vector<int> row;
    for (int j = 0; j < pixels.size(); j++) {
      int number = get_number(pixels, i, j);
      char output = algorithm[number];
      if (output == '#') {
        row.push_back(1);
      } else {
        row.push_back(0);
      }
    }
    enhanced.push_back(row);
  }
  return enhanced;
}

int count_lit(std::vector<std::vector<int>> pix, int times, int original_size) {
  // I bet there is a better data structure for modelling this
  // but already this far so let's make do.
  // As we have a # in pos 0 of the real puzzle algorithm
  // this is going to make adding up the values tricky (as we're going to
  // add 0s at the edges which get counted when we don't want them to.
  // So instead we're iterating n times, at each iteration the dimensions get
  // 2 bigger in every direction. So if we use padding > times * 2
  // then exclude values outside of 2 * times for our counting, we should
  // get the answer
  int total_lit = 0;
  int final_size = original_size + (4 * times);
  int start_index = (pix.size() - final_size) / 2;
  int end_index = pix.size() - start_index;
  for (int i = start_index; i < end_index; i++) {
    for (int j = start_index; j < end_index; j++) {
      if (pix[i][j]) {
        total_lit++;
      }
    }
  }
  return total_lit;
}

std::vector<std::vector<int>> pad_pixels(const std::vector<std::vector<int>> & pixels, int times) {
  // Apply some padding around them so that we have enough pixels to be
  // dealing with any infinite space
  int height = pixels.size();
  int width = pixels[0].size();
  // Image grows in steps of 2 in each direction each time, so pad
  // image enough to fit all of the "infinite" pixels which are interesting
  // I then just added some arbitrary buffer because I was getting the wrong
  // anaswer ¯\_(ツ)_/¯
  int padding = times * 2 + 51;
  std::vector<std::vector<int>> pix;
  for (int i = 0; i < width + (2 * padding); i++) {
    std::vector<int> row;
    for (int j = 0; j < width + (2 * padding); j++) {
      if (i < padding || i > width + padding - 1 || j < padding || j > height + padding - 1) {
        row.push_back(0);
      } else {
        row.push_back(pixels[i - padding][j - padding]);
      }
    }
    pix.push_back(row);
  }
  return pix;
}

//' Get the number of pixels lit in
//'
//' @param pixels The
//' @param small_caves The number of times you can visit a small cave
//' @param verbose If TRUE print the completed paths
//' @return The total number of complete caves
//' @export
// [[Rcpp::export]]
int get_number_of_pixels_lit(std::vector<std::string> pixels, std::string algorithm, int times) {
  std::vector<std::vector<int>> pix;
  for (auto& i: pixels) {
    std::vector<int> row;
    for (auto& j: i) {
      if (j == '#') {
        row.push_back(1);
      } else {
        row.push_back(0);
      }
    }
    pix.push_back(row);
  }
  pix = pad_pixels(pix, times);
  for (size_t i = 0; i < times; i++) {
    pix = enhance_pixles(pix, algorithm);
  }

  return count_lit(pix, times, pixels.size());
}
