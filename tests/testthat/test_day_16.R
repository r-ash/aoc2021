test_that("can get package sums", {
  expect_equal(sum_version_numbers(c("D2FE28")), 6)
  expect_equal(sum_version_numbers(c("8A004A801A8002F478")), 16)
  expect_equal(sum_version_numbers(c("620080001611562C8802118E34")), 12)
  expect_equal(sum_version_numbers(c("C0015000016115A2E0802F182340")), 23)
  expect_equal(sum_version_numbers(c("A0016C880162017C3686B18A3D4780")), 31)

  expect_equal(sum_version_numbers(c("D2FE28",
                                     "8A004A801A8002F478",
                                     "620080001611562C8802118E34",
                                     "C0015000016115A2E0802F182340",
                                     "A0016C880162017C3686B18A3D4780")), 88)
})

test_that("can get package values", {
  expect_equal(get_package_value(c("C200B40A82")), 3)
  expect_equal(get_package_value(c("04005AC33890")), 54)
  expect_equal(get_package_value(c("880086C3E88112")), 7)
  expect_equal(get_package_value(c("CE00C43D881120")), 9)
  expect_equal(get_package_value(c("D8005AC2A8F0")), 1)
  expect_equal(get_package_value(c("F600BC2D8F")), 0)
  expect_equal(get_package_value(c("9C005AC2F8F0")), 0)
  expect_equal(get_package_value(c("9C0141080250320F1802104A08")), 1)
})
