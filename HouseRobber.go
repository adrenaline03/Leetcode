func rob(nums []int) int {
    rob1 := 0;
    rob2 := 0;

    for i := 0; i < len(nums); i++ {
        temp := max(nums[i] + rob1, rob2)
        rob1 = rob2
        rob2 = temp
    }

    return rob2
}