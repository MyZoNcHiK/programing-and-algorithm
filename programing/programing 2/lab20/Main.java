package lab20;
interface Downloadable{public void download();}
interface Streamable{public void stream();}
class Movie implements Downloadable, Streamable {
    public Movie(){}
    @Override
    public void download(){System.out.println("щось завантажується");}
    public void stream(){System.out.println("щось транслюється");}
}
public class Main {
    public void main(String[] args){
        Movie movie = new Movie();
        movie.download();
        movie.stream();
    }
}