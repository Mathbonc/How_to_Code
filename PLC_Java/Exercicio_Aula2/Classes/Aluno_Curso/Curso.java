package Exercicio_Aula2.Classes.Aluno_Curso;

public class Curso {
    private String name;
    private int ID;

    public Curso (String name, int ID){
        this.name = name;
        this.ID = ID;
    }

    // GETTERS
    public int getID(){
        return this.ID;
    }
    public String getName(){
        return this.name;
    }

    // SETTERS
    public void setID(int ID){
        this.ID = ID;
    }
    public void setName(String name){
        this.name = name;
    }

    // UTILLS
    public void printCourse(){
        System.out.println("Curso: " + this.name);
        System.out.println("ID: " + this.ID);
    }
}
