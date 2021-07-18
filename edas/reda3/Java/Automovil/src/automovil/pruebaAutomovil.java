/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package automovil;

import java.util.Scanner;

/**
 *
 * @author mngomezz
 */
public class pruebaAutomovil
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        System.out.print("Ingrese anio del auto de Luis:");
        int anioLuis = Integer.parseInt(entrada.nextLine());
        System.out.print("Ingrese marca del auto de Luis:");
        String marcaLuis = entrada.nextLine();
        System.out.print("Ingrese modelo del auto de Luis:");
        String modeloLuis = entrada.nextLine();

        System.out.print("Ingrese anio del auto de Juan:");
        int anioJuan = Integer.parseInt(entrada.nextLine());
        System.out.print("Ingrese marca del auto de Juan:");
        String marcmartinaJuan = entrada.nextLine();
        System.out.print("Ingrese modelo del auto de Juan:");
        String modeloJuan = entrada.nextLine();

        Automovil autoDeLuis = new Automovil(marcaLuis, modeloLuis, anioLuis);
        Automovil autoDeJuan = new Automovil(marcaJuan, modeloJuan, anioJuan);

        autoDeLuis.recorre(30);
        autoDeLuis.recorre(40);
        autoDeLuis.recorre(220);
        autoDeJuan.recorre(60);
        autoDeJuan.recorre(150);
        autoDeJuan.recorre(90);
        System.out.println(autoDeJuan.toString());
        System.out.println(autoDeLuis.toString());
        System.out.println("El coche de Luis ha recorrido "
                + autoDeLuis.getKilometraje() + "Km");
        System.out.println("El coche de Juan ha recorrido "
                + autoDeJuan.getKilometraje() + "Km");
        System.out.println("El kilometraje total ha sido de "
                + Automovil.getKilometrajeTotal() + "Km");
    }
}
