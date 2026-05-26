package lab22;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        File file = new File("example.txt");
        try{if (file.createNewFile()){
                System.out.println("Файл створено: " + file.getName());
            }else{
                System.out.println("Файл уже існує.");
            }
        }catch (IOException e){
            System.out.println("Виникла помилка.");
            e.printStackTrace();
        }
        if (!file.exists()){
            System.out.println("Файл не існує!");
            return;
        }
        System.out.println("Ім'я: " + file.getName());
        System.out.println("Абсолютний шлях: " + file.getAbsolutePath());
        System.out.println("Розмір (байт): " + file.length());
        System.out.println("Чи можна читати: " + file.canRead());
        System.out.println("Чи можна дозаписувати: " + file.canWrite());
        System.out.println("Введіть текст: ");
        String text = scanner.nextLine();
        try (FileWriter writer = new FileWriter(file, true)){
            writer.write(text + System.lineSeparator());
            System.out.println("Текст успішно додано до файлу!");
        } catch (IOException e){
            System.out.println("Помилка при записі у файл: " + e.getMessage());
        }
        scanner.close();
    }
}
