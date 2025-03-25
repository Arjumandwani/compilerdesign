import java.util.regex.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();
        
        String[] keywords = {"abstract", "assert", "boolean", "break", "byte", "case", "catch", "char", "class", "const", "continue", 
                             "default", "do", "double", "else", "enum", "extends", "final", "finally", "float", "for", "goto", 
                             "if", "implements", "import", "instanceof", "int", "interface", "long", "native", "new", "null", 
                             "package", "private", "protected", "public", "return", "short", "static", "strictfp", "super", "switch", 
                             "synchronized", "this", "throw", "throws", "transient", "try", "void", "volatile", "while"};
        
        if (str.length() == 0) {
            System.out.println(str + " is not a valid identifier.");
            return;
        }

        // Check if it's a keyword
        for (String keyword : keywords) {
            if (str.equals(keyword)) {
                System.out.println(str + " is not a valid identifier.");
                return;
            }
        }

        // Check if it's a valid identifier
        if (str.matches("^[A-Za-z_][A-Za-z0-9_]*$")) {
            System.out.println(str + " is a valid identifier.");
        } else {
            System.out.println(str + " is not a valid identifier.");
        }
    }
}
