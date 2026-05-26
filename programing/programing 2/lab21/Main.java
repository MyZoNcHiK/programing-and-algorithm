package lab21;
class Camera{
    int resultion;
    Lens lens;
    Camera(int resultion){
        this.resultion = resultion;
        lens = new Lens();
    }
    class Lens{
        void focus(){
            System.out.println("Фокусування об'єктива для роздільної здатності " + resultion);
        }
    }
}
public class Main {
    static void main(String[] args){
    Camera camera = new Camera(15);
        camera.lens.focus();
    }
}
