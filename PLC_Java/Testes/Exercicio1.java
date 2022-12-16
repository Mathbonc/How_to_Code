package Testes;
import java.util.Scanner;

public class Exercicio1 {
    public static void main (String[] args){
        Scanner input = new Scanner (System.in);
        System.out.println("Digite o nome completo: ");
        
        String a;
        a = input.nextLine();
        a = a.trim();

        System.out.println(a);
        input.close();
    }
}
