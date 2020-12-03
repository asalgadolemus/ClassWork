public class StackOfIntegersTest {

   public static void main(String[] args) {
       //Create object of class StackOfIntegers
       StackOfIntegers st=new StackOfIntegers();
       //store values in stack
       st.push(1);
       st.push(2);
       st.push(3);
       st.push(4);
       st.push(5);
       st.push(6);
       st.push(7);
       st.push(8);
       st.push(9);
       System.out.println("Pop all elements in the stack, you will get:");
       //display values from the stack
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       System.out.print(st.pop()+" ");
       }

}

