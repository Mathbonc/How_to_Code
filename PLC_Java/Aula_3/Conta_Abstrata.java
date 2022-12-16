package Aula_3;

public abstract class Conta_Abstrata {
    private String numero;
    private double saldo;

    public Conta_Abstrata(String numeroInicial, double saldoInicial) {
      numero = numeroInicial;
      saldo = saldoInicial;
    }

    public Conta_Abstrata(String numeroInicial) {
      this(numeroInicial,0);
    }

    public void creditar(double valor) {
      saldo += valor; 
    }

    public abstract void debitar(double valor);  // { }

    public double getSaldo() {
       return saldo; 
    }

    public String getNumero() {
         return numero; 
    }

    protected void setSaldo(double saldo) {
        this.saldo = saldo;
    }
}