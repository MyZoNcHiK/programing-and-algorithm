package lab23;
import java.util.ArrayList;
class User {
    String email;
    String password;
    User(String email,String password){
        this.email=email;
        this.password=password;
    }
}
class DataBaseManager{
    static ArrayList<User> Users=new ArrayList<>();
    static void AddUser(User user){
        Users.add(user);
        System.out.println("User added: "+user.email);
    }
    static User GetUser(String email){
        for(User u:Users){
            if(u.email.equals(email))return u;
        }
        return null;
    }
    static boolean UserIsAlreadyExcist(String email){
        return GetUser(email)!=null;
    }
}
class UserLoginAndRegistration{
    static void Login(String email,String password){
        User u=DataBaseManager.GetUser(email);
        if(u!=null&&u.password.equals(password)){
            System.out.println("User authorized");
        }else{
            System.out.println("Invalid data");
        }
    }
    static void Register(String email,String password){
        if(!DataBaseManager.UserIsAlreadyExcist(email)){
            DataBaseManager.AddUser(new User(email,password));
        }else{
            System.out.println("User already exists");
        }
    }
}
public class Main{
    static void main(String[] args){
        UserLoginAndRegistration.Register("test@mail.com", "1234");
        UserLoginAndRegistration.Register("test@mail.com", "1234");
        UserLoginAndRegistration.Login("test@mail.com", "1234");
        UserLoginAndRegistration.Login("test@mail.com", "0000");
    }
}