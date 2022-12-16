package Q1;

public class Robot {
    private String rName;
    private int rNum;
    private int[] rPos = new int[2];


    public Robot(String rName){
        this.rName = rName;
        this.rNum = -1;
        this.rPos[0] = this.rPos[1] = -1;
    }

    public Robot(String rName, int rNum, int rX, int rY){
        this.rName = rName;
        this.rNum = rNum;

        this.rPos[0] = rX;
        this.rPos[1] = rY;
    }

}
