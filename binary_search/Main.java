public class Main{
  public static void main (String[] args){
    int array[] = {1, 3, 5, 8, 13, 21, 34, 42, 55, 89};
    int target = 42;
    int size = array.length;
    int left = 0;
    int right = size - 1;
    int index = binarySearch(target, array, left, right);
    System.out.println(index);
    System.out.println("if the answer is write you have the number if false it be -1");
  }
  public static int binarySearch(int target ,int[] array ,int left, int right){
    while(left <= right){
      int middle = (left + right)/2;
      if (target < array[middle]){
        right = middle - 1;
      } else if (target > array[middle]){
        left = middle +1;
      }
      return middle;
    }
    return -1;

  }
}
