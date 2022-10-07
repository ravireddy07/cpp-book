import java.util.Scanner;

abstract class Car {
    abstract void setPrice(double p);
    abstract void setModel(String s);
    abstract void getPrice();
    abstract void getModel();
}

class Color extends Car {
    String Model;
    double Price;

    void setPrice(double p) {
        Price = p;
        return;
    }

    void setModel(String s) {
        Model = s;
        return;
    }

    void getPrice() {
        System.out.println("Color Instance Price: " + Price);
        return;
    }

    void getModel() {
        System.out.println("Color Instance Model: " + Model);
        return;
    }
}

class Company extends Car {
    String Model;
    double Price;

    void setPrice(double p) {
        Price = p;
        return;
    }

    void setModel(String s) {
        Model = s;
        return;
    }

    void getPrice() {
        System.out.println("Company Instance Price: " + Price);
        return;
    }

    void getModel() {
        System.out.println("Company Instance Model: " + Model);
        return;
    }
}

public class test {
    public static void main(String args[]) {
        Car a = new Color();
        a.setModel("Audi");
        a.setPrice(2000);
        a.getModel();
        a.getPrice();

        System.out.println();

        Car b = new Company();
        b.setModel("Benz");
        b.setPrice(3000);
        b.getModel();
        b.getPrice();
    }
}