public class SearchArr {
    public static boolean searchNum(int[] arr,int a) {
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==a)
            {
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5,};
        int a = 3;
        if(searchNum(arr, a))
        {
            System.out.println("Element is present in array");
        }
        else
        {
            System.out.println("Element is not present in array");
        }
    }
}
