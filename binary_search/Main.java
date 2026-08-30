import java.util.Arrays;
public class Main{
  public static void main (String[] args){
    int array[] = new int[100];
    int target = 42;
    int index;
    int size = array.length;
    int left = 0;
    int right = size - 1;
    index = binarySearch(target, array, left, right);


  }
  public int binarySearch(int target ,int[] array ,int left, int right){
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
