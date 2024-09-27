struct Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i = 0;
        for j in 0..nums.len() {
            if nums[j] != val {
                nums[i] = nums[j];
                i += 1;
            }
        }
        i as i32
    }
}

fn main() {
    let mut nums = vec![0, 1, 2, 2, 3, 3, 0, 4, 2];
    let val = 2;
    let size = Solution::remove_element(&mut nums, val);
    println!("{}",size)
}
