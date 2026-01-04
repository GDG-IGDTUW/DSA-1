# Q1. Can Place Flowers

Suppose you have a long flowerbed in which some of the plots are planted, and some are not. However, no two flowers can be planted in adjacent plots.

Given an integer array `flowerbed` containing `0`s and `1`s, where `0` means empty and `1` means not empty, and an integer `n`, return `true` if `n` new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and `false` otherwise.

## Sample Test Cases

- Input: `flowerbed = [1,0,0,0,1]`, `n = 1`
  Output: `true`

- Input: `flowerbed = [1,0,0,0,1]`, `n = 2`
  Output: `false`

## Constraints

- `1 <= flowerbed.length <= 2 * 10^4`
- `flowerbed[i]` is `0` or `1`
- No two adjacent flowers are planted in `flowerbed`
- `0 <= n <= flowerbed.length`