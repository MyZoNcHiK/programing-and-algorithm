package lab18;

class Animal {
    protected String name;
    public Animal(String name) {
        this.name = name;
    }
    public void makeNoice() {
        System.out.println("noice");
    }
}
class Amphibian extends Animal {
    public Amphibian(String name) {
        super(name);
    }
    @Override 
    public void makeNoice() {
        System.out.println(name + " Amphibian noice");
    }
}
class Mammal extends Animal {
    public Mammal(String name) {
        super(name);
    }
    @Override
    public void makeNoice() {
        System.out.println(name + " Mammal noice");
    }
}
class Reptile extends Animal {
    public Reptile(String name) {
        super(name);
    }
    @Override
    public void makeNoice() {
        System.out.println(name + " Reptile noice");
    }
}
class Dog extends Mammal {
    public Dog(String name) {
        super(name);
    }
    @Override
    public void makeNoice() {
        System.out.println(name + " woof");
    }
}
class Cat extends Mammal {
    public Cat(String name) {
        super(name);
    }
    @Override
    public void makeNoice() {
        System.out.println(name + " meow");
    }
}
class Cow extends Mammal {
    public Cow(String name) {
        super(name);
    }
    @Override
    public void makeNoice() {
        System.out.println(name + "  moo");
    }
}
public class Main {
    public static void main(String[] args) {
        Animal a1 = new Amphibian("Frog");
        Animal a2 = new Reptile("Snake");
        Animal a3 = new Dog("Bobik");
        Animal a4 = new Cat("Barsik");
        Animal a5 = new Cow("Myna1");

        a1.makeNoice();
        a2.makeNoice();
        a3.makeNoice();
        a4.makeNoice();
        a5.makeNoice();
    }
}
