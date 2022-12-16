package Exercicio_Aula2.Classes;

public class Produto {
    private String name;
    private String description;
    private float price;
    private int qnty;

    // Constructor
    public Produto(String name, String description, float price, int qnty){
        this.name = name;
        this.description = description;
        this.price = price;
        this.qnty = qnty;
    }
    
    public Produto(String name){
        this(name,"", 0, 0);
    }

    // Getters    
    public int getQuantity(){
        return this.qnty;
    }
    public float getPrice(){
        return this.price;
    }
    public String getDescription(){
        return this.description;
    }
    public String getName(){
        return this.name;
    }

    // Setters
    public void setQuantity(int qnty){
        this.qnty = qnty;
    }
    public void setPrice(float price){
        this.price = price;
    }
    public void setDescription(String desc){
        this.description = desc;
    }
    //Utils
    public void printProduct(){
        System.out.println("Nome do produto: " + this.name);
        System.out.println("Descrição: " + this.description);
        System.out.println("Preço: " + this.price);
        System.out.println("Quantidade: " + this.qnty);
    }
}
