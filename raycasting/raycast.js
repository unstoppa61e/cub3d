const TILE_SIZE = 64;
const MAP_NUM_ROWS = 11;
const MAP_NUM_COLS = 15;

const WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE;
const WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;

const FOV_ANGLE = 60 * (Math.PI / 180)

const WALL_STRIP_WIDTH = 1;
const NUM_RAYS = WINDOW_WIDTH / WALL_STRIP_WIDTH;

const EDGE_COLOR = "#15d";
const INNER_COLOR = "#d51";

const NEUTRAL = 0;
const LEFT = -1;
const RIGHT = 1;
const BACK = -1;
const FRONT = 1;

class Map {
	constructor() {
		this.grid = [
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
            [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
		];
	}
	isSpaceAt(pixelX, pixelY) {
		if (isOutOfWindow(pixelX, pixelY))
			return false;
		const gridX = Math.floor(pixelX / TILE_SIZE);
		const gridY = Math.floor(pixelY / TILE_SIZE);
		return this.grid[gridY][gridX] === 0 ? true : false;
	}
	hasWallAt(pixelX, pixelY) {
		if (isOutOfWindow(pixelX, pixelY))
			return true;
		const gridX = Math.floor(pixelX / TILE_SIZE);
		const gridY = Math.floor(pixelY / TILE_SIZE);
		return this.grid[gridY][gridX] === 1 ? true : false;
	}
	render() {
		for (let y = 0; y < MAP_NUM_ROWS; y++) {
			for (let x = 0; x < MAP_NUM_COLS; x++) {
				const tileX = x * TILE_SIZE;
				const tileY = y * TILE_SIZE;
				const tileColor = this.grid[y][x] === 1 ? EDGE_COLOR : INNER_COLOR;
				stroke(EDGE_COLOR);
				fill(tileColor);
				rect(tileX, tileY, TILE_SIZE, TILE_SIZE);
			}
		}
	}
}

class	Player {
	constructor() {
		this.x = WINDOW_WIDTH / 2;
		this.y = WINDOW_HEIGHT / 2;
		this.radius = 3;
		this.turnDirection = NEUTRAL;
		this.walkDirection = NEUTRAL;
		this.rotationAngle = Math.PI / 2;
		this.moveSpeed = 2.0;
		this.rotationSpeed = 2 * (Math.PI / 180);

	}
	update() {
		this.rotationAngle += this.turnDirection * this.rotationSpeed;

		const	moveStep = this.walkDirection * this.moveSpeed;

		const	moveX = Math.cos(this.rotationAngle) * moveStep;
		const	moveY = Math.sin(this.rotationAngle) * moveStep;

		let		newPlayerX = this.x;
		let		newPlayerY = this.y;

		if (grid.isSpaceAt(this.x + moveX, this.y)) {
			newPlayerX += moveX;
		}
		if (grid.isSpaceAt(this.x, this.y + moveY)) {
			newPlayerY += moveY;
		}
		[this.x, this.y] = [newPlayerX, newPlayerY];
	}
	render() {
		noStroke();
		fill("yellow");
		circle(this.x, this.y, this.radius);
		// stroke("rgba(55, 255, 255)");
		// line(
		// 	this.x,
		// 	this.y,
		// 	this.x + Math.cos(this.rotationAngle) * 30,
		// 	this.y + Math.sin(this.rotationAngle) * 30
		// );
	}
}

class Ray {
	constructor(rayAngle) {
		this.rayAngle = normalizeAngle(rayAngle);
		this.wallHitX = 0;
		this.wallHitY = 0;
		this.distance = 0;
		this.wasHitVertical = false;

		this.isRayFacingDown = this.rayAngle > 0 && this.rayAngle < Math.PI;
		this.isRayFacingUp = !this.isRayFacingDown;

		this.isRayFacingRight = this.rayAngle < Math.PI / 2 || this.rayAngle > Math.PI * (3 / 2);
		this.isRayFacingLeft = !this.isRayFacingRight;

	}
	cast(columnId) {
		let xintercept, yintercept;
		let xstep, ystep;

		///////////////////////////////////////////
		// HORIZONTAL RAY-GRID INTERSECTION CODE //
		///////////////////////////////////////////
		let foundHorzWallHit = false;
		let	horzWallHitX = 0;
		let	horzWallHitY = 0;

		// Find the y-coordinate of the closest horizontal grid intersection
		yintercept = Math.floor(player.y / TILE_SIZE) * TILE_SIZE;
		if (this.isRayFacingDown)
			yintercept += TILE_SIZE;

		// Find the x-coordinate of the closest horizontal grid intersection
		xintercept = player.x + (yintercept - player.y) / Math.tan(this.rayAngle);

		// Calculate the increment xstep and y step
		ystep = this.isRayFacingDown ? TILE_SIZE : -TILE_SIZE;

		xstep = TILE_SIZE / Math.tan(this.rayAngle);
		if ((this.isRayFacingLeft && xstep > 0) || (this.isRayFacingRight && xstep < 0))
			xstep *= -1;

		let nextHorzTouchX = xintercept;
		let nextHorzTouchY = yintercept;

		// if (this.isRayFacingUp)
		// 	nextHorzTouchY--;

		// increment xstep and ystep until we find a wall
		while (!isOutOfWindow(nextHorzTouchX, nextHorzTouchY)) {
			// if (grid.hasWallAt(nextHorzTouchX, nextHorzTouchY - this.isRayFacingUp ? 1 : 0)) {
			if (grid.hasWallAt(nextHorzTouchX, nextHorzTouchY - (this.isRayFacingUp) ? 1 : 0)) {
				foundHorzWallHit = true;
				horzWallHitX = nextHorzTouchX;
				horzWallHitY = nextHorzTouchY;
				break;
			}
			nextHorzTouchX += xstep;
			nextHorzTouchY += ystep;
		}

		///////////////////////////////////////////
		// VERTICAL RAY-GRID INTERSECTION CODE //
		///////////////////////////////////////////
		let foundVertWallHit = false;
		let	vertWallHitX = 0;
		let	vertWallHitY = 0;

		// Find the x-coordinate of the closest vertical grid intersection
		xintercept = Math.floor(player.x / TILE_SIZE) * TILE_SIZE;
		if (this.isRayFacingRight)
			xintercept += TILE_SIZE;

		// Find the y-coordinate of the closest vertical grid intersection
		yintercept = player.y + (xintercept - player.x) * Math.tan(this.rayAngle);

		// Calculate the increment xstep and y step
		xstep = this.isRayFacingRight ? TILE_SIZE : -TILE_SIZE;

		ystep = TILE_SIZE * Math.tan(this.rayAngle);
		if ((this.isRayFacingUp && ystep > 0) || (this.isRayFacingDown && ystep < 0))
			ystep *= -1;

		let nextVertTouchX = xintercept;
		let nextVertTouchY = yintercept;

		// if (this.isRayFacingLeft)
		// 	nextVertTouchX--;

		// increment xstep and ystep until we find a wall
		while (!isOutOfWindow(nextVertTouchX, nextVertTouchY)) {
			// if (grid.hasWallAt(nextVertTouchX - this.isRayFacingLeft ? 1 : 0, nextVertTouchY)) {
			if (grid.hasWallAt(nextVertTouchX - (this.isRayFacingLeft) ? 1 : 0, nextVertTouchY)) {
				foundVertWallHit = true;
				vertWallHitX = nextVertTouchX;
				vertWallHitY = nextVertTouchY;
				break;
			}
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}

		const horzHitDistance = (foundHorzWallHit)
			? distanceBetweenPoints(player.x, player.y, horzWallHitX, horzWallHitY)
			: Number.MAX_VALUE;
		const vertHitDistance = (foundVertWallHit)
			? distanceBetweenPoints(player.x, player.y, vertWallHitX, vertWallHitY)
			: Number.MAX_VALUE;
		[this.wallHitX, this.wallHitY, this.distance, this.wasHitVertical] = horzHitDistance < vertHitDistance
			? [horzWallHitX, horzWallHitY, horzHitDistance, false]
			: [vertWallHitX, vertWallHitY, vertHitDistance, true];


	}
	render() {
		stroke("rgba(55, 255, 255, 1.0)");
		line(
			player.x,
			player.y,
			this.wallHitX,
			this.wallHitY
		);
	}
}

const	grid = new Map();
const	player = new Player();
let		rays = [];

function keyPressed() {
	switch (keyCode) {
		case UP_ARROW:
			player.walkDirection = FRONT;
			break;
		case DOWN_ARROW:
			player.walkDirection = BACK;
			break;
		case LEFT_ARROW:
			player.turnDirection = LEFT;
			break;
		case RIGHT_ARROW:
			player.turnDirection = RIGHT;
			break;
	}
}

function keyReleased() {
	switch (keyCode) {
		case UP_ARROW:
		case DOWN_ARROW:
			player.walkDirection = NEUTRAL;
			break;
		case LEFT_ARROW:
		case RIGHT_ARROW:
			player.turnDirection = NEUTRAL;
			break;
	}
}

function castAllRays() {
	let columnId = 0;

	// start first ray subtracting half of the FOV
	let rayAngle = player.rotationAngle - (FOV_ANGLE / 2);

	rays = [];

	// loop all columns casting the rays
	// for (let i = 0; i < 1; i++) {
	for (let i = 0; i < NUM_RAYS; i++) {
		const ray = new Ray(rayAngle);
		ray.cast(columnId);
		rays.push(ray);

		rayAngle += FOV_ANGLE / NUM_RAYS;

		columnId++;
	}
}

function normalizeAngle(angle) {
	let normalAngle;

	normalAngle = angle;
	while (normalAngle < 0)
		normalAngle += 2 * Math.PI;
	if (normalAngle > 2 * Math.PI)
		normalAngle %= (2 * Math.PI);
	return (normalAngle);
}

function setup() {
	createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);
}

function update() {
	player.update();
	castAllRays();
}

function draw() {
	update();

	grid.render();
	for (ray of rays) {
		ray.render();
	}
	player.render();

}

function distanceBetweenPoints(x1, y1, x2, y2) {
	return (Math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2));
}

function isOutOfWindow(x, y) {
	return (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT);
}