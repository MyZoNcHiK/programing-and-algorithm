package lab17;

public class Camera {
    private String resolution;
    private String brand;
    private double price;

    private static int cameraCount = 0;
    public Camera() {
        this.resolution = "Unknown";
        this.brand = "Unknown";
        this.price = 0.0;
        cameraCount++;
    }
    public Camera(String resolution, String brand, double price) {
        this.resolution = resolution;
        this.brand = brand;
        this.price = price;
        cameraCount++;
    }
    public Camera(Camera other) {
        this.resolution = other.resolution;
        this.brand = other.brand;
        this.price = other.price;
        cameraCount++;
    }
    public static void printCameraCount() {
        System.out.println("Кількість створених об'єктів Camera: " + cameraCount);
    }
    public void printInfo() {
        System.out.println("Brand: " + brand);
        System.out.println("Resolution: " + resolution);
        System.out.println("Price: " + price);
    }
    public static void main(String[] args) {
        Camera c1 = new Camera();
        Camera c2 = new Camera("24MP", "Canon", 799.99);
        Camera c3 = new Camera(c2);

        c1.printInfo();
        c2.printInfo();
        c3.printInfo();

        Camera.printCameraCount();
    }
}