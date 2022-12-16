package Aula_3;

public class Banco {
    private Conta_Abstrata[] contas;
    private int indice;
    double taxa = 1.1;

    public Banco(){
        contas = new Conta_Abstrata[100];
        indice = 0;
    }

    public void cadastrarConta(Conta_Abstrata c){
        contas[indice] = c;
        indice += 1;
    }

    public Conta_Abstrata procurarConta(String numero){
        int i = 0;
        boolean found = false;
        Conta_Abstrata resposta = null;

        while((!found) && (i<indice)){
            if(contas[i].getNumero().equals(numero)){
                found = true;
                resposta = contas[i];
            }else{
                i += 1;
            }
        }

        if(!found){
            throw new RuntimeException("Not Found");
        }

        return resposta;
    }

    public void debitarConta (String numero, double valor){
        Conta_Abstrata c;
        c = this.procurarConta(numero);
        c.debitar(valor);
    }

    public void creditarConta (String numero, double valor){
        Conta_Abstrata c;
        c = this.procurarConta(numero);
        c.creditar(valor);
    }

    public double getSaldo (String numero){
        Conta_Abstrata c;
        c = this.procurarConta(numero);
        return c.getSaldo();
    }

    public void renderJuros(String numero){
        Conta_Abstrata c;
        c = this.procurarConta(numero);
        if(c instanceof Poupanca){
            ((Poupanca) c).renderJuros(this.taxa);
        }
    }

    public void renderBonus(String numero){
        Conta_Abstrata c;
        c = this.procurarConta(numero);
        if(c instanceof Conta_Especial){
            ((Conta_Especial) c).renderBonus();
        }
    }

    public void transferir(String debitar, String creditar, double valor){
        Conta_Abstrata c1,c2;
        c1 = this.procurarConta(debitar);
        c2 = this.procurarConta(creditar);
        c1.debitar(valor);
        c2.creditar(valor);
    }
}
