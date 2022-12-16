package Aula_3;

public class Conta extends Conta_Abstrata {

    public Conta(String numeroInicial, double saldoInicial) {
        super(numeroInicial,saldoInicial);
    }

    public Conta(String numeroInicial) {
        this(numeroInicial,0);
    }

    public void debitar(double valor) {
        super.setSaldo(getSaldo() - valor); 
    }
}
