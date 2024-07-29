// This is the function to find min containers
function find_min_container(shipments, container_limits)
{
    // first we will sort them in descending order
    shipments.sort((x,y) =>
    {
        return y -x;
    })

    container_limits.sort((x, y) =>
    {
        return y - x;
    })
    // Initially we consider a index 0 for container_limits array
    let con_index = 0; 

    for(let i = 0; i < shipments.length; i++)
    {
        let ship_unit = shipments[i];

            while (ship_unit > 0) {
                if (con_index >= container_limits.length) {
                    return -1;
                }
                if (container_limits[con_index] >= ship_unit) {
                    container_limits[con_index]-= ship_unit;
                    ship_unit = 0;
                } else {
                    ship_unit -= container_limits[con_index];
                    con_index++;
                }
            }
    }
    return con_index + 1;
}


let shipments = [10, 20, 30,];
let container_limits = [15, 15, 20, 5,5];

let min_container = find_min_container(shipments, container_limits);

console.log(min_container);

