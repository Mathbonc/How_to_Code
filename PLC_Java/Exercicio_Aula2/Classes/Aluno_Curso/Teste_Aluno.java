package Exercicio_Aula2.Classes.Aluno_Curso;

public class Teste_Aluno {
    public static void main (String[] args){
        Curso curso = new Curso("Engenaria da Computação", 69);
        Aluno aluno = new Aluno("Matheus Bonc", 21, "123.456.789-69", curso);
        Aluno aluno2 = new Aluno("Janovitz Novais", 19);

        aluno.printAluno();
        System.out.println();
        aluno2.printAluno();
        aluno2.setCPF("112.113.556-30");
        aluno2.setCourse(curso);
        aluno2.printAluno();
    }
}
