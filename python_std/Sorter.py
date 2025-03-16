import math

class Sorter:
    @staticmethod
    def insertion_sort(arr):
        for i in range(arr.len):
            for j in range(arr.len):
                min_num = min(min_num, arr[j])
                min_idx = j;
            arr[min_idx] = math.inf


def main():
    print(Sorter.insertion_sort([1,2,3]))
    print(f"{Sorter.insertion_sort([1,2,3])}")

if __name__ == "__main__":
    main()