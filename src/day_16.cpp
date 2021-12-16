#include <Rcpp.h>
#include <math.h>
#include <string>
#include "day_16.h"


std::string hex_to_bin(const std::string &s) {
  std::string out;
  for(auto i: s){
    uint8_t n;
    if(i <= '9' and i >= '0')
      n = i - '0';
    else
      n = 10 + i - 'A';
    for(int8_t j = 3; j >= 0; --j)
      out.push_back((n & (1<<j))? '1':'0');
  }

  return out;
}

// [[Rcpp::export]]
int64_t bin_to_int(std::string bin) {
  int64_t total = 0;
  int64_t multiplier = 1;
  reverse(bin.begin(), bin.end());
  for (auto& it: bin) {
    total += ((int64_t)(it) - 48) * multiplier;
    multiplier *= 2;
  }
  return total;
}

struct Packet {
  std::string bin;
  int start_index;
  int length;
  int packet_version;
  int type_id;
  int oper;
  std::vector<Packet> sub_packets;
  int64_t value = 0;

  Packet(const std::string bin, const int start_index): bin(bin), start_index(start_index) {
    parse_packet();
  }

  int total_size() {
    int total_size = 0;
    if (sub_packets.size() == 0) {
      return 1;
    }
    for (auto& pack: sub_packets) {
      total_size += pack.total_size();
    }
    return total_size;
  }

  void parse_packet() {
    packet_version = bin_to_int(bin.substr(start_index, 3));
    type_id = bin_to_int(bin.substr(start_index + 3, 3));
    if (type_id == 4) {
      int numbers_index = start_index + 6;
      int not_last = 1;
      std::string number = "";
      while (not_last) {
        not_last = bin_to_int(bin.substr(numbers_index, 1));
        number += bin.substr(numbers_index + 1, 4);
        numbers_index += 5;
      }
      value = bin_to_int(number);
      length = numbers_index - start_index;
    } else {
      oper = bin_to_int(bin.substr(start_index + 6, 1));
      if (oper == 0) {
        // We know length of subpackets
        int sub_packet_length = bin_to_int(bin.substr(start_index + 7, 15));
        int preamble_length = 7 + 15;
        int sub_packet_start = start_index + 7 + 15;
        int packets_length = 0;
        while (packets_length < sub_packet_length) {
          Packet pack = Packet(bin, sub_packet_start);
          sub_packets.push_back(pack);
          sub_packet_start += pack.length;
          packets_length += pack.length;
        }
        length = preamble_length + sub_packet_length;
      } else {
        // We know no of subpackets
        int no_packets = bin_to_int(bin.substr(start_index + 7, 11));
        int sub_packet_start = start_index + 7 + 11;
        for (int i = 0; i < no_packets; i++) {
          Packet pack = Packet(bin, sub_packet_start);
          sub_packets.push_back(pack);
          sub_packet_start += pack.length;
        }
        length = sub_packet_start - start_index;
      }
    }
  }

  int sum_packet() {
    int sum = 0;
    for (auto& packet: sub_packets) {
      sum += packet.sum_packet();
    }
    return sum + packet_version;
  }

  int64_t get_value() {
    int64_t total_value = 0;
    if (type_id == 4) {
      total_value = value;
    } else if (type_id == 0) {
      int i = 0;
      for (auto& packet: sub_packets) {
        i++;
        total_value += packet.get_value();
      }
    } else if (type_id == 1) {
      int64_t value = 1;
      for (auto& packet: sub_packets) {
        value *= packet.get_value();
      }
      total_value = value;
    } else if (type_id == 2) {
      int64_t min = sub_packets[0].get_value();
      for (auto& packet: sub_packets) {
        int64_t val = packet.get_value();
        if (val < min) {
          min = val;
        }
      }
      total_value = min;
    } else if (type_id == 3) {
      int64_t max = 0;
      for (auto& packet: sub_packets) {
        if (packet.get_value() > max) {
          max = packet.get_value();
        }
      }
      total_value = max;
    } else {
      std::vector<int64_t> values;
      for (auto& packet: sub_packets) {
        values.push_back(packet.get_value());
      }
      if (type_id == 5) {
        total_value = values[0] > values[1];
      } else if (type_id == 6) {
        total_value = values[0] < values[1];
      } else {
        total_value = values[0] == values[1];
      }
    }

    return total_value;
  }
};


//' Sum version numbers of all packets
//'
//' @param input The packet hexadecimal
//' @return The sum of version numbers
//' @export
// [[Rcpp::export]]
int sum_version_numbers(std::vector<std::string> input) {
  int sum = 0;
  for (auto& i: input) {
    std::string bin = hex_to_bin(i);
    Packet packet = Packet(bin, 0);
    sum += packet.sum_packet();
  }
  return sum;
}


//' Get the value of package
//'
//' @param input The packet hexadecimal
//' @return The sum of version numbers
//' @export
// [[Rcpp::export]]
int64_t get_package_value(std::vector<std::string> input) {
  int64_t value = 0;
  for (auto& i: input) {
    std::string bin = hex_to_bin(i);
    Packet packet = Packet(bin, 0);
    value += packet.get_value();
  }
  return value;
}
