package Exercicio_Aula2.Classes.Aluno_Curso;

public class Aluno {
    private String name,CPF;
    private int age;
    private Curso course;

    // Constructor
    public Aluno (String name, int age, String CPF, Curso course){
        this.name = name;
        this.age = age;
        this.CPF = CPF;
        this.course = course;
    }
    public Aluno (String name, int age){
        this(name, age, "N/A", null);
    }

    // GETTERS
    public String getName(){
        return this.name;
    }
    public String getCPF(){
        return this.CPF;
    }
    public int getAge(){
        return this.age;
    }
    public Curso getCourse(){
        return this.course;
    }

    // SETTERS
    public void setName(String name){
        this.name = name;
    }
    public void setCPF(String CPF){
        this.CPF = CPF;
    }
    public void setAge(int age){
        this.age = age;
    }
    public void setCourse(Curso course){
        this.course = course;
    }

    // UTILLS
    public void printAluno(){
        System.out.println("Nome: " + this.name);
        System.out.println("Idade: " + this.age);
        System.out.println("CPF: " + this.CPF);
        if(this.course != null){
            System.out.println("--Informações do curso--");
            this.course.printCourse();
            System.out.println("------------------------");
        }
    }
}
