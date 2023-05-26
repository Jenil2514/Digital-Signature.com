public class recursion {
    public static int sum(int start,int end){
        int add;
        if(end>start){
            add=end+sum(start,end-1);
            return add;
        }
        else{
            return end;
        }
    }
    public static void main(String[] args) {
       
        System.out.println( sum(5, 10));

    }
}
