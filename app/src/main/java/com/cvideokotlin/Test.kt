package com.cvideokotlin

data class Test(val id:Int,val name: String)

fun main(args:Array<String>):Unit{
    println("hello ")

    var test = Test(1,"hello")

    println(test.name)

    var i :Int =2
    println(i)

    var ii = 2;
    println(ii)

    println(hello(5))

    var intArray = IntArray(5)
    var anotherArray = intArrayOf(1,2,3,4,5)


}

fun hello(id: Int):Unit{
    println(id)
}