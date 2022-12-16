package Aula_3;

public class Conta_Especial extends Conta { 
    private double bonus;
    
    public Conta_Especial(String numero) {
        super(numero);
        this.bonus = 0.0;
    }
    public void renderBonus() {
        super.creditar(this.bonus);
        this.bonus = 0.0;
    }
    public double getBonus() {
        return this.bonus;
    }
    public void creditar (double valor){
        super.creditar(valor);
        bonus += (valor*0.01);
    }
}
