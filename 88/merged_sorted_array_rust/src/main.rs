struct Solution;

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let (mut i, mut j, mut k) = (m as isize-1, n as isize-1, (m+n) as isize-1);

        while i >= 0 && j >= 0 {
            if nums1[i as usize] > nums2[j as usize] {
                nums1[k as usize] = nums1[i as usize];
                i-=1;
            }
            else {
                nums1[k as usize] = nums2[j as usize];
                j-=1;
            }
            k-=1;
        }

        while j >= 0 {
            nums1[k as usize] = nums2[j as usize];
            j-=1;
            k-=1;
        }
    }

    pub fn print_array(nums: &Vec<i32>, size: i32) {
        print!("[");
        for (i, &num) in nums.iter().enumerate().take(size as usize) {
            print!("{}", num);
            if i < (size as usize - 1) {
                print!(", ");
            }
        }
        println!("]");
    }
}


fn main() {
    let mut nums1 = vec![1, 3, 5, 0, 7, 8];
    let m = 3;
    let mut nums2 = vec![2, 4, 6];
    let n = 2;

    println!("Before merging:");
    Solution::print_array(&nums1, m);
    Solution::print_array(&nums2, n);

    Solution::merge(&mut nums1, m, &mut nums2, n);

    println!("After merging:");
    Solution::print_array(&nums1, (m+n) as i32);
}
