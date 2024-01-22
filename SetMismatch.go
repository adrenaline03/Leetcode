func findErrorNums(nums []int) []int {
  n := len(nums)
  mp := map[int]int{}

  for _, num := range nums {
    mp[num]++
  }

  var duplicate, missing int
  for num, count := range mp {
    if count == 2 {
      duplicate = num
    } else if count == 0 {
      missing = num
    }
  }

  if missing == 0 {
    for i := 1; i <= n; i++ {
      if _, ok := mp[i]; !ok {
        missing = i
        break
      }
    }
  }

  return []int{duplicate, missing}
}
