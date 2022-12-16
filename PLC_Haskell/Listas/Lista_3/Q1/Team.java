package Q1;

public class Team {
    private Robot[] teamMain;
    private Robot[] teamRes;

    public Team (){
        this.teamMain = new Robot[6];
        this.teamRes = new Robot[6];
    }

    public Team (Robot[] teamMain, Robot[] teamRes){
        if(teamMain.length < 7){
            this.teamMain = teamMain;
        }else{
            throw new RuntimeException("New Team: Max teamMain reached!");
        }
        
        if(teamRes.length < 7){
            this.teamRes = teamRes;
        }else{
            throw new RuntimeException("New Team: Max teamRes reached!");
        }
    }
    
    public void addRobotMain (Robot robot){
        if(this.teamMain.length < 6){
            this.teamMain[this.teamMain.length] = robot;
        }else{
            throw new RuntimeException("Max teamMain reached!");
        }
    }

    public void addRobotRes (Robot robot){
        if(this.teamRes.length < 6){
            this.teamRes[this.teamRes.length] = robot;
        }else{
            throw new RuntimeException("Max teamRes reached!");
        }
    }
}
