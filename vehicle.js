function helperSeperator()
{
    console.log('-----------------------------------');
}

function Vehicle(type, space, headlight, registration_id)
{
    this.type = type;
    this.space = space;
    this.headlight = headlight;
    this.registration_id = registration_id;
    this.Honk = function()
    {
        console.log(this.type + ' ' + 'Honks');
    }
    this.PutonTheLight = function()
    {
        this.headlight = 'on';
    }
    this.PutoffTheLight = function()
    {
        this.headlight = 'off';
    }
    this.inspectVehicle = function()
    {
        helperSeperator();
        console.log('Type : ' + this.type);
        console.log('Space : ' + this.space);
        console.log('Headlight : ' + this.headlight);
        console.log('Registration_ID : ' + this.registration_id);
        helperSeperator();
    }
}

function Car(model, owner, lights, registration_id)
{
    Vehicle.call(this, 'Car', 4, lights, registration_id);
    this.wheels = 4;
    this.model = model;
    this.owner = owner;
}

Car.prototype = new Vehicle();
Car.prototype.constructor = Car;

function Truck(model, owner, lights, registration_id)
{
    Vehicle.call(this, 'Truck', 8, lights, registration_id);
    this.wheels = 8;
    this.model = model;
    this.owner = owner;
}

Truck.prototype = new Vehicle();
Truck.prototype.constructor = Truck;

function Bike(model, owner, lights, registration_id)
{
    Vehicle.call(this, 'Bike', 2, lights, registration_id);
    this.wheels = 2;
    this.model = model;
    this.owner = owner;
}

Bike.prototype = new Vehicle();
Bike.prototype.constructor = Bike;


var vehiclesAllowed = ['Car', 'Truck', 'Bike'];
var modelsAllowed = {
    'Car':['Tesla', 'Lamborghini', 'Maruti', 'Audi'],
    'Truck':['Bantam', 'Coleman', 'LaFrance'],
    'Bike':['Royal Enfield', 'Bajaj', 'Harley Davidson']
};

var ownerFirstName = ['Ralph', 'Amrit', 'Bina', 'Sakshi', 'Tina', 'Tommy'];
var ownerLastName = ['Das', 'Sharma', 'Gonzales', 'Prasad', 'Pandey'];
var light_state = ['off', 'on'];

function Parking_Floor(space, vehiclesAllowed)
{
    this.vehiclesAllowed = vehiclesAllowed;
    this.space = space;
    this.free_space = space;
    this.allocation =[];
    for(var i = 0; i < space; i++)
        this.allocation.push('O');

    this.allocate_vehicle = function(vehicle)
    {
        var flag = 0;
        for(var i = 0; i < this.vehiclesAllowed.length; i++)
            if(this.vehiclesAllowed[i] == vehicle.type)
                flag = 1;
        if(flag == 0)
        {
            return 0;
        }

        console.log('Allocating vehicle : ' + vehicle.type + ' ' + flag);
        var i = 0, sz = 0;
        for(i; i < this.space; i++)
        {

            if(this.allocation[i] != 'O')
                sz = 0;
            else
                sz++;
            if(sz == vehicle.space)
            {
                i = i-sz + 1;
                break;
            }
        }

        if(i != space)
        {
            //console.log('\tProcessing space : ' + i + 'sz == ' + sz);
            for (var j = i; j < i + vehicle.space; j++)
                this.allocation[j] = vehicle.registration_id;
            console.log('Allocated!');
            return 1;
        }
        else
        {
            console.log('Not Allocated!');
            return 0;
        }
    }

    this.inspectFloor = function()
    {
        var vehicles = '';
        for(var i = 0; i < this.vehiclesAllowed.length; i++)
            vehicles += this.vehiclesAllowed[i] + ' ';

        console.log('Vehicles Allowed : '+vehicles);
        console.log(this.allocation);
    }

}




function addVehicles(vehiclesAvailable)
{
    var vehiclesToAdd = Math.floor(Math.random()*10)+1;
    for(var i = 0; i < vehiclesToAdd; i++)
    {
        var type = vehiclesAllowed[Math.floor(Math.random()*3)];
        var model = modelsAllowed[type][Math.floor(Math.random()*(modelsAllowed[type].length))];
        var owner = ownerFirstName[Math.floor(Math.random()*ownerFirstName.length)] + ' ' + ownerLastName[Math.floor(Math.random()*ownerLastName.length)];
        var registration = 'AB';
        var reg_no = Math.floor(Math.random()*1000);
        registration = registration + reg_no;
        var lights = light_state[Math.floor((Math.random()*2))];
        switch(type)
        {
            case 'Car':
                var CC = new Car(model, owner, lights, registration);
                break;
            case 'Bike':
                var CC = new Bike(model, owner, lights, registration);
                break;
            case 'Truck':
                var CC = new Truck(model, owner, lights, registration);
                break;
            default:
                var CC = new Car(model, owner, lights, registration);
        }
        vehiclesAvailable.push(CC);
        //vehiclesAvailable.push(new (Car(model, owner, lights, registration+reg_no)));
    }
}


var Floor = [new Parking_Floor(20, ['Truck', 'Car']),new Parking_Floor(15, ['Car']),new Parking_Floor(10, ['Car', 'Bike'])];

Floor[0].inspectFloor();
Floor[1].inspectFloor();
Floor[2].inspectFloor();


var vehiclesAvailable = [];


//var Audi = new Car('Audi', 'on', 'SKSXXX');

console.log(Audi.prototype);


addVehicles(vehiclesAvailable);
console.log(vehiclesAvailable);

function allocatevehicles()
{
    console.log('Allocating Vehicles Now!');
    for(var i = 0; i < vehiclesAvailable.length; i++)
    {
        for(var j = 0; j < Floor.length; j++)
        {
            if(Floor[j].allocate_vehicle(vehiclesAvailable[i]))
            {
                console.log('Vehicle allocated to floor : '+ j);
                break;
            }
        }
    }
}

allocatevehicles();


Floor[0].inspectFloor();
Floor[1].inspectFloor();
Floor[2].inspectFloor();
