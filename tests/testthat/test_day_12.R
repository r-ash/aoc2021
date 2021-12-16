test_that("can get total no of paths", {
  expect_equal(get_num_paths(list(
    c("start", "A"),
    c("start", "b"),
    c("A", "c"),
    c("A", "b"),
    c("b", "d"),
    c("A", "end"),
    c("b", "end")
  ), small_caves = 1, verbose = TRUE), 10)

  expect_equal(get_num_paths(list(
    c("dc", "end"),
    c("HN", "start"),
    c("start", "kj"),
    c("dc", "start"),
    c("dc", "HN"),
    c("LN", "dc"),
    c("HN", "end"),
    c("kj", "sa"),
    c("kj", "HN"),
    c("kj", "dc")
  ), small_caves = 1, verbose = TRUE), 19)

  expect_equal(get_num_paths(list(
    c("fs", "end"),
    c("he", "DX"),
    c("fs", "he"),
    c("start", "DX"),
    c("pj", "DX"),
    c("end", "zg"),
    c("zg", "sl"),
    c("zg", "pj"),
    c("pj", "he"),
    c("RW", "he"),
    c("fs", "DX"),
    c("pj", "RW"),
    c("zg", "RW"),
    c("start", "pj"),
    c("he", "WI"),
    c("zg", "he"),
    c("pj", "fs"),
    c("start", "RW")
  ), small_caves = 1, verbose = FALSE), 226)
})

test_that("can get total no of paths visiting small caves twice", {
  expect_equal(get_num_paths(list(
    c("start", "A"),
    c("start", "b"),
    c("A", "c"),
    c("A", "b"),
    c("b", "d"),
    c("A", "end"),
    c("b", "end")
  ), small_caves = 2, verbose = TRUE), 36)

  expect_equal(get_num_paths(list(
    c("dc", "end"),
    c("HN", "start"),
    c("start", "kj"),
    c("dc", "start"),
    c("dc", "HN"),
    c("LN", "dc"),
    c("HN", "end"),
    c("kj", "sa"),
    c("kj", "HN"),
    c("kj", "dc")
  ), small_caves = 2, verbose = TRUE), 103)

  expect_equal(get_num_paths(list(
    c("fs", "end"),
    c("he", "DX"),
    c("fs", "he"),
    c("start", "DX"),
    c("pj", "DX"),
    c("end", "zg"),
    c("zg", "sl"),
    c("zg", "pj"),
    c("pj", "he"),
    c("RW", "he"),
    c("fs", "DX"),
    c("pj", "RW"),
    c("zg", "RW"),
    c("start", "pj"),
    c("he", "WI"),
    c("zg", "he"),
    c("pj", "fs"),
    c("start", "RW")
  ), small_caves = 2, verbose = FALSE), 3509)
})
