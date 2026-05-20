package lab19;
class Book{
    String title, author;

    public Book(String title, String author) {
        this.title = title; this.author = author;
    }
    void showDiscription(){
        System.out.println("title: " + title + " author: " + author);
    }
}
class EBook extends Book{
    double filesize;
    public EBook(double filesize, String title,String author){
        super(title, author);
    }
    @Override
    void showDiscription(){
        System.out.println("filesize: " + filesize + " title: " + title + " author: " + author);
    }
}
public class Books{
    public static void main(String[] args){
        EBook ebook1 = new EBook(5.3, "Програмування", "хтось");
        EBook ebook2 = new EBook(3.5, "Алгоритми", "ще хтось");
        ebook1.showDiscription();
        ebook2.showDiscription();
    }
}
